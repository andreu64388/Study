//во всех сервисах я буду заносить 10 записей
const Sequelize = require('sequelize');
const config = require('./config.json');
const db = require('./context')(Sequelize, config);
const server = require('./server')(db, config);

//там заносится тек. время
async function clientSim(id) {
    db.model.create({id: id, data: Date.now() + 7200000, clNum: 1})
}

(async function () {
    // await db.sequelize.sync();
    setInterval(async () => {
        db.model.count().then((count) => {
            if (count >= 13) {
                // server.logger.debug('truncate db');
                // db.model.destroy({where: {}, truncate: true})
            } else {
                for (let i = count; i < 13; i++) {
                    clientSim(i + 1);
                }
            }
        });
    }, 20000);
    server.listen(8001, () => console.log('Server is running'));
})();
