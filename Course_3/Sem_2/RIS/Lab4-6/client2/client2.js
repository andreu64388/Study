const Sequelize = require('sequelize');
const config = require('./config.json');
const db = require('./context')(Sequelize, config);
const server = require('./server')(db, config);

async function clientSim(id) {
    db.model.create({id: id, data: (Date.now() + 7200000), clNum: 2})
}

(async function () {
    setInterval(async () => {
        db.model.count().then((count) => {
            if (count >= 13) {
                // db.model.destroy({where: {}, truncate: true})
            } else {
                for (let i = count; i < 13; i++) {
                    clientSim(i + 1);
                }
            }
        });
    }, 20000);

    server.listen(8003, () => console.log('Server is running'));
})();