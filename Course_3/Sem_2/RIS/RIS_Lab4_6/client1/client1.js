//во всех сервисах я буду заносить 10 записей

const Sequelize = require('sequelize');
const config = require('./config.json');
const db = require('./context')(Sequelize, config);
const server = require('./server')(db, config);

//там заносится тек. время
async function clientSim(id) {
    db.model.create({id: id, data: Date.now() + 7200000, clNum: 1})
}

// если в бд <10 записей, добавляем еще до 10
// i+1;  Date.now;  clNum: 1
// занесли 10 == уничтожаем и заносим заново (через 10 сек)


(async function () {
    await db.sequelize.sync();
    setInterval(async () => {
        db.model.count().then((count) => {
            if (count >= 10) {
                server.logger.debug('truncate db');
                //db.model.destroy({where: {}, truncate: true})
            } else {
                for (let i = count; i < 10; i++) {
                    server.logger.debug('create entity');
                    clientSim(i + 1);
                }
            }
        });
    }, 20000);
    server.listen(8001, "0.0.0.0", () => console.log('Server is running'));
})();
