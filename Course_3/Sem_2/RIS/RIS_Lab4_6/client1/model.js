module.exports = (Sequelize, sequelize) => {
    return sequelize.define('model_cl1', {
        id: {
            type: Sequelize.INTEGER,
            primaryKey: true,
            autoIncrement: true
        },
        data: Sequelize.DATE,
        clNum: Sequelize.INTEGER,
    });

};