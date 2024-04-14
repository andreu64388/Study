const Sequelize = require('sequelize');
const config = require('./config.json');
const db = require('./context')(Sequelize, config);
const server = require('./server')(db, config);

server.listen(8005, () =>console.log('Server is running'));
