const express = require('express');
const cookieParser = require('cookie-parser');
const bodyParse = require('body-parser');
const axios = require('axios');
const moment = require('moment')
const cors = require('cors')

module.exports = (db) => {
    const app = express();

    app.use(cors())
    app.use(cookieParser());
    app.use(bodyParse.json());

    app.get('/listen', async function (req, res) {
        console.log('Start fetching data every 10 seconds');

        setInterval(() => {
            axios.get('http://localhost:8001/get')
                .then(res => {
                    replicateDB(res.data, 1);
                })
                .catch((e) => {
                    console.log(e)
                })
        }, 10000);

        setInterval(() => {
            axios.get('http://localhost:8003/get')
                .then(res => {
                    replicateDB(res.data, 2);
                })
                .catch((e) => {
                    console.log(e)
                })
        }, 10000);

        res.sendStatus(200);
    });

    app.get('/get', async function (req, res) {
        const data = await db.model.findAll();
        res.end(JSON.stringify(data, null, '\t'));
    });

    app.get('/getTime', async function (req, res) {
        let mnt = moment();
        res.end(JSON.stringify(mnt));
    });

    app.get('/set', async function (req, res) {
        axios.get('http://localhost:8001/update');
        axios.get('http://localhost:8003/update');
        res.json({});
    });

    //вызов на клиентах
    app.post('/resource', async (req, res) => {
        let data = req.body;
        let item = await db.model.findOne({
            where: {
                clNum: data.clNum,
                clNumId: data.id
            }
        });
        if (item) {
            res.json({data: item.data, clNum: item.clNum, id: item.clNumId});
        } else {
            let response = await axios.get(`http://localhost:800${data.clNum === 1 ? 3 : 1}/get`);
            let filter_data = await response.data.filter(iter => iter.id === data.id);
            if (!filter_data.length) {
                res.json({data: filter_data[0].data, clNum: filter_data[0].clNum, id: filter_data[0].id});
            } else {
                res.statusCode = 400;
                res.json({'status': 'error'});
            }
        }
    });

    async function replicateDB(data, clNum)    //data - localhost:8003/get
    {
        for (let i = 0; i < data.length; i++) {
            let item = await db.model.findOne({
                where: {
                    clNum: data[i].clNum,
                    clNumId: data[i].id
                }
            });
            if (clNum === data[i].clNum) {
                if (!item) {
                    // db.model.destroy({where: {'clNum': data[i].clNum, 'clNumId': data[i].id}, truncate: true})
                    await db.model.create({'data': data[i].data, 'clNum': data[i].clNum, 'clNumId': data[i].id});
                }
                // await db.model.create({'data': data[i].data, 'clNum': data[i].clNum, 'clNumId': data[i].id});
            } else {
            }
        }
    }

    return app;
};