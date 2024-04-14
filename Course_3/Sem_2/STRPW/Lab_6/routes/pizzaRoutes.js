import { Router } from "express";
import * as pizzaController from "../controllers/pizzaController.js";

const router = Router();

router.get('/', (req, res, next) => {
    const { calories } = req.query;
    console.log("calories:", calories);
    if (calories !== undefined) {
        return pizzaController.getPizzasByCalories(req, res, next);
    } else {
        return pizzaController.getAllPizzas(req, res, next);
    }
});
router.get('/:id', pizzaController.getPizzasById);
router.post('/', pizzaController.postNewPizza);
router.put('/:id', pizzaController.updatePizzaById);
router.delete('/:id', pizzaController.deletePizzaById);

export default router;
