module.exports = (Sequelize, config) => {
    const options = {
        dialect: config.dialect,
        host: config.host
    };
    const sequelize = new Sequelize(config.db.name, config.db.user, config.db.password, options);

    const Model = require('./model')(Sequelize, sequelize);
    sequelize.sync({force:true});
    return {
        model: Model,
        sequelize,
        Sequelize,
    };
};