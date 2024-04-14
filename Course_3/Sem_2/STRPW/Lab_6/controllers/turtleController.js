import turtleService from '../services/turtleService.js';

export const getAllTurtles = async (req, res) => {
    try {
        const turtles = await turtleService.getAllTurtles();
        res.json(turtles);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const getTurtlesById = async (req, res) => {
    const { id } = req.params;

    try {
        const turtles = await turtleService.getTurtlesById(id);
        res.json(turtles);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const getTurtlesByFavouritePizza = async (req, res) => {
    const { favoritePizza } = req.query;

    console.log(favoritePizza)
    try {
        const turtles = await turtleService.getTurtlesByFavouritePizza(favoritePizza);
        res.json(turtles);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const postNewTurtle = async (req, res) => {
    try {
        const turtleBody = req.body;
        const newTurtle = await turtleService.postNewTurtle(turtleBody);
        res.status(201).json(newTurtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const updateTurtleById = async (req, res) => {
    try {
        const { id } = req.params;
        const turtleBody = req.body;

        delete turtleBody.id;

        const turtle = await turtleService.updateTurtleById(id, turtleBody);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const deleteTurtleById = async (req, res) => {
    try {
        const { id } = req.params;
        const turtle = await turtleService.deleteTurtleById(id);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const bindFavoritePizzaTurtle = async (req, res) => {
    try {

        console.log("work")
        const  { id } = req.params;


        const pizzaId = req?.body?.pizzaId;
       console.log(pizzaId)
        console.log(pizzaId+"pizza id")

        console.log(id+" id")


        const turtle = await turtleService.bindFavoritePizzaTurtle(id, pizzaId);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const bindSecondFavoritePizzaTurtle = async (req, res) => {
    try {
        const turtleId = req.body.id;
        const pizzaId = req.body.pizzaId;
        const turtle = await turtleService.bindSecondFavoritePizzaTurtle(turtleId, pizzaId);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const bindWeaponTurtle = async (req, res) => {
    try {
        const { id } = req.params;
        const weaponId = req.body.weaponId;
        const turtle = await turtleService.bindWeaponTurtle(id, weaponId);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const unbindWeaponTurtle = async (req, res) => {
    try {
        const { id } = req.params;
        const turtle = await turtleService.unbindWeaponTurtle(id);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const unbindFavoritePizzaTurtle = async (req, res) => {
    try {
        const { id } = req.params;
        const turtle = await turtleService.unbindFavoritePizzaTurtle(id);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}

export const unbindSecondFavoritePizzaTurtle = async (req, res) => {
    try {
        const turtleId = req.body.id;
        const turtle = await turtleService.unbindSecondFavoritePizzaTurtle(turtleId);
        res.status(201).json(turtle);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
}
