const express = require('express');
const cookieParser = require('cookie-parser');
const bodyParse = require('body-parser');
const axios = require('axios');
const cors = require('cors')

module.exports = (db) => {
    const app = express();

    app.use(cors())
    app.use(cookieParser());
    app.use(bodyParse.json());

    app.post('/add', async function (req, res) { //добавляем в модель тело запроса
        const data = {
            data: req.body.data,
            clNum: 1
        };
        const item = await db.model.create(data);
        res.json(item.get({plain: true}))
    });

    app.get('/get', async function (req, res) { //возвр записи
        const data = await db.model.findAll();
        res.end(JSON.stringify(data, null, '\t'));
    });

    app.get('/update', async (req, res) => //синхронизация с центральной БД
    {
        let response = await axios.get('http://localhost:8005/get');
        await db.model.destroy({where: {}, truncate: true});

        response.data = await response.data.filter(data => data.clNum === 2 && data.clNumId < 6);
        for (let i = 0; i < response.data.length; i++) {
            let data = response.data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            await db.model.create(data);
        }
        res.statusCode = 200;
        res.json({'status': 'OK'})
    });
    app.get('/sTime', async function (req, res) {
        let response = await axios.get('http://localhost:8005/getTime');
        let mnt = moment();
        let smnt = response.data;
        console.log("diff " + mnt.diff(smnt, 'milliseconds'));
        res.sendStatus(200);
    });

    app.get('/sync', async (req, res) => // синхронизация одной строки (id:3,дата,clNum: 2)
    {
        try {
            //ищет строку в центр. БД
            await axios.get('http://localhost:8005/get/')
              .then(res => replicateDB(res.data));

            res.statusCode = 200;
            res.send("success");
        } catch (e) {
            res.statusCode = 400;
            res.send("err");
        }
    });

    app.post('/set', async (req, res) => {
        await db.model.destroy({where: {}, truncate: true});
        //ищет первые 5 записей клиента 2 (в теле запроса)
        let t_data = await req.body.filter(data => data.clNum === 2 && data.clNumId < 6);

        for (let i = 0; i < t_data.length; i++) {
            let data = t_data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            //добавляет их в свою БД
            await db.model.create(data);
        }

        res.statusCode = 200;
        res.json({'status': 'OK'})
    });

    async function replicateDB(data)    //data - localhost:8003/get
    {
        console.log(data)
        for (let i = 0; i < data.length; i++) {
            let item = await db.model.findOne({
                where: {
                    clNum: data[i].clNum,
                    id: data[i].clNumId
                }
            });
            if (item) {
                // db.model.destroy({where: {'clNum': data[i].clNum, 'id': data[i].clNumId}, truncate: true})
                // await db.model.create({'data': data[i].data, 'clNum': data[i].clNum});
            } else {
                await db.model.create({'data': data[i].data, 'clNum': data[i].clNum});
            }
        }
    }

    return app;
};
