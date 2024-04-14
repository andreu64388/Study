const express = require('express');
const cookieParser = require('cookie-parser');
const bodyParse = require('body-parser');
const axios = require('axios');
const log4js = require('log4js');
const moment = require('moment')

log4js.configure({
    appenders: {'file': {type: 'file', filename: 'logs/log.log'}},
    categories: {default: {appenders: ['file'], level: 'debug'}}
});

const logger = log4js.getLogger();

const serverIp = '127.0.0.1';

module.exports = (db) => {
    const app = express();

    app.use(cookieParser());
    app.use(bodyParse.json());

    app.post('/add', async function (req, res) {
        const data = {
            data: req.body.data,
            clNum: 2
        };
        const item = await db.model.create(data);
        res.json(item.get({plain: true}))
    });

    app.get('/get', async function (req, res) {
        const data = await db.model.findAll();
        res.end(JSON.stringify(data, null, '\t'));
        logger.debug('Add');
    });

    app.get('/sTime', async function (req, res) {
        let response = await axios.get(`http://${serverIp}:8005/getTime`);
        let mnt = moment();
        let smnt = response.data;
        console.log( mnt.diff(smnt, 'milliseconds'));
        res.json({diff: mnt.diff(smnt, 'milliseconds')});
    });

    app.get('/update', async (req, res) => {
        logger.debug('restore from central data base');
        let response = await axios.get(`http://${serverIp}:8005/get`);
        await db.model.destroy({where: {}, truncate: true});

        response.data = await response.data.filter(data => data.clNum === 1 && data.clNumId < 6);
        for (let i = 0; i < response.data.length; i++) {
            let data = response.data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            logger.debug('restore ' + data);
            await db.model.create(data);
        }
        res.statusCode = 200;
        res.json({'status': 'OK'})
    });

    app.get('/sync', async (req, res) => {
        try {
            let response = await axios.post(`http://${serverIp}:8005/resource/`, {"id": 3, "clNum": 1});
            logger.debug(`successful sync ${response.data}`);
            let data = response.data;
            data.id = 11;
            db.model.create(data);
            res.sendStatus(200);
        } catch (e) {
            logger.debug('not found');
        }

    });


    app.post('/set', async (req, res) => {
        await db.model.destroy({where: {}, truncate: true});
        let t_data = await req.body.filter(data => data.clNum === 1 && data.clNumId < 6);
        for (let i = 0; i < t_data.length; i++) {
            let data = t_data[i];
            data.id = data.clNumId;
            delete data.clNumId;
            logger.debug('restore ' + data);
            await db.model.create(data);
        }

        res.statusCode = 200;
        res.json({'status': 'OK'})
    });

    app.logger = logger;
    return app;
};
