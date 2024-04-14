
import { Router } from "express";
import * as turtleController from '../controllers/turtleController.js';

const turtlesRouter = Router();

turtlesRouter.get('/', async (req, res, next) => {
    if (req.query.favoritePizza) {
        return turtleController.getTurtlesByFavouritePizza(req, res, next);
    } else {
        return turtleController.getAllTurtles(req, res, next);
    }
});

turtlesRouter.get('/:id', turtleController.getTurtlesById);
turtlesRouter.post('/', turtleController.postNewTurtle);
turtlesRouter.put('/:id', turtleController.updateTurtleById);
turtlesRouter.delete('/:id', turtleController.deleteTurtleById);
turtlesRouter.put('/favoritePizzaBind/:id', turtleController.bindFavoritePizzaTurtle);
turtlesRouter.put('/weaponBind/:id', turtleController.bindWeaponTurtle);
turtlesRouter.delete('/weaponUnbind/:id', turtleController.unbindWeaponTurtle);
turtlesRouter.delete('/favoritePizzaUnbind/:id', turtleController.unbindFavoritePizzaTurtle);
export default turtlesRouter;
