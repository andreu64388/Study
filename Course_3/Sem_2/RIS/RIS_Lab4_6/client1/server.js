const express = require('express');
const cookieParser = require('cookie-parser');
const bodyParse = require('body-parser');
const axios = require('axios');
const log4js = require('log4js');
const moment = require('moment')

//конфигурирую файл логов
log4js.configure({
    appenders: { 'file': { type: 'file', filename: 'log.log' } },
    categories: { default: { appenders: ['file'], level: 'debug' } }
});
const logger = log4js.getLogger();

const serverIp = '26.167.130.120';

module.exports = (db) => {
    const app = express();


    app.use(cookieParser());
    app.use(bodyParse.json());

    app.post('/add', async function (req, res) { //добавляем в модель тело запроса
        const data = {
            data: req.body.data,
            clNum: 1
        };
        const item = await db.model.create(data);
        res.json(item.get({ plain: true }))
    });

    app.get('/get', async function (req, res) { //возвр записи
        const data = await db.model.findAll();
        res.end(JSON.stringify(data, null, '\t'));
        logger.debug('Add');
    });

    app.get('/update', async (req, res) => //синхронизация с центральной БД
    {
        logger.debug('restore from central data base');
        let response = await axios.get(`http://${serverIp}:8005/get`);
        await db.model.destroy({ where: {}, truncate: true });

        response.data = await response.data.filter(data => data.clNum === 2 && data.clNumId < 6);
        for (let i = 0; i < response.data.length; i++) {
            let data = response.data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            logger.debug('restore ' + JSON.stringify(data));
            await db.model.create(data);
        }
        res.statusCode = 200;
        res.json({ 'status': 'OK' })
    });

    app.get('/sTime', async function (req, res) {
        let response = await axios.get(`http://${serverIp}:8005/getTime`);
        let mnt = moment();
        let smnt = response.data;
        console.log("diff " + mnt.diff(smnt, 'milliseconds'));
        res.json({ diff: mnt.diff(smnt, 'milliseconds') });
    });

    app.get('/sync', async (req, res) => // синхронизация одной строки (id:3,дата,clNum: 2)
    {
        try {
            //ищет строку в центр. БД
            let response = await axios.post(`http://${serverIp}:8005/resource/`, { "id": 3, "clNum": 2 });
            logger.debug('successful sync ');
            let data = response.data;
            //добавляем ее в свою БД с id:11
            data.id = 11;
            db.model.create(data);
            res.statusCode = 200;
            res.send("success");
        } catch (e) {
            logger.debug('not found');
            res.statusCode = 400;
            res.send("err");
        }
    });

    app.post('/set', async (req, res) => {
        await db.model.destroy({ where: {}, truncate: true });
        //ищет первые 5 записей клиента 2 (в теле запроса)
        let t_data = await req.body.filter(data => data.clNum === 2 && data.clNumId < 6);

        for (let i = 0; i < t_data.length; i++) {
            let data = t_data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            logger.debug('restore ' + data);
            //добавляет их в свою БД
            await db.model.create(data);
        }

        res.statusCode = 200;
        res.json({ 'status': 'OK' })
    });

    app.logger = logger;
    return app;
};