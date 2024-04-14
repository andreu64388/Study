const Sequelize = require('sequelize');
const config = require('./config.json');
const db = require('./context')(Sequelize, config);
const server = require('./server')(db, config);

async function clientSim(id) {
    db.model.create({id: id, data: (Date.now() + 7200000), clNum: 2})
}

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
    }, 10000);

    server.listen(8002, "0.0.0.0", () => console.log('Server is running'));
})();