//ЦЕНТРАЛЬНЫЙ ВЕБ-СЕРВЕР

const express = require("express");
const cookieParser = require("cookie-parser");
const bodyParse = require("body-parser");
require("bluebird");
const axios = require("axios");
const log4js = require("log4js");
const moment = require("moment");

log4js.configure({
    appenders: { file: { type: "file", filename: "log.log" } },
    categories: { default: { appenders: ["file"], level: "debug" } },
});
const logger = log4js.getLogger();

const clientIp = '127.0.0.1';

module.exports = (db) => {
    const app = express();

    app.use(cookieParser());
    app.use(bodyParse.json());

    app.get("/listen", async function (req, res) {
        console.log("Start fetching data every 10 seconds");

        setInterval(() => {
            logger.debug("fetch from 1");
            axios
                .get(`http://${clientIp}:8001/get`)
                .then((res) => {
                    logger.debug("from 1: " + res.data.length);
                    replicateDB(res.data);
                })
                .catch(() => {
                    logger.debug("error 1");
                });
        }, 10000);

        setInterval(() => {
            logger.debug("fetch from 2");
            axios
                .get(`http://${clientIp}:8002/get`)
                .then((res) => {
                    logger.debug("from 2: " + res.data.length);
                    replicateDB(res.data);
                })
                .catch(() => {
                    logger.debug("error 2");
                });
        }, 10000);

        res.sendStatus(200);
    });

    app.get("/get", async function (req, res) {
        logger.debug("send db");
        const data = await db.model.findAll();
        res.end(JSON.stringify(data, null, "\t"));
    });

    app.get("/getTime", async function (req, res) {
        let mnt = moment();
        logger.debug(mnt);
        res.end(JSON.stringify(mnt));
    });

    app.get("/set", async function (req, res) {
        axios.get(`http://${clientIp}:8001/update`);
        axios.get(`http://${clientIp}:8002/update`);
        res.end("ok");
    });

    //вызов на клиентах
    app.post("/resource", async (req, res) => {
        let data = req.body;
        let item = await db.model.findOne({
            where: {
                clNum: data.clNum,
                clNumId: data.id,
            },
        });
        if (item) {
            res.json({ data: item.data, clNum: item.clNum, id: item.clNumId });
        } else {
            let response = await axios.get(
                `http://${clientIp}:800${data.clNum === 1 ? 2 : 1}/get`
            );
            let filter_data = await response.data.filter(
                (iter) => iter.id === data.id
            );
            if (!filter_data.length) {
                res.json({
                    data: filter_data[0].data,
                    clNum: filter_data[0].clNum,
                    id: filter_data[0].id,
                });
            } else {
                res.statusCode = 400;
                res.json({ status: "error" });
            }
        }
    });

    async function replicateDB(data) {
        //data - localhost:8002/get
        for (let i = 0; i < data.length; i++) {
            let item = await db.model.findOne({
                where: {
                    clNum: data[i].clNum,
                    clNumId: data[i].id,
                },
            });
            if (item) {
                db.model.destroy({
                    where: { clNum: data[i].clNum, clNumId: data[i].id },
                    truncate: true,
                });
                await db.model.create({
                    data: data[i].data,
                    clNum: data[i].clNum,
                    clNumId: data[i].id,
                });
                logger.debug(
                    "upd: " +
                    JSON.stringify({
                        data: data[i].data,
                        clNum: data[i].clNum,
                        clNumId: data[i].id,
                    })
                );
            } else {
                await db.model.create({
                    data: data[i].data,
                    clNum: data[i].clNum,
                    clNumId: data[i].id,
                });
                logger.debug(
                    "add: " +
                    JSON.stringify({
                        data: data[i].data,
                        clNum: data[i].clNum,
                        clNumId: data[i].id,
                    })
                );
            }
        }
    }

    return app;
};
