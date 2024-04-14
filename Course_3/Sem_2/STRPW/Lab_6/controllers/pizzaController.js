import pizzaService from '../services/pizzaService.js';

export const getAllPizzas = async (req, res) => {
    try {
        const pizzas = await pizzaService.getAllPizzas();
        res.json(pizzas);
    } catch (error) {
        throw new Error(error.message);
    }
};

export const getPizzasById = async (req, res) => {
    const { id } = req.params;

    try {
        const pizza = await pizzaService.getPizzasById(id);
        if (!pizza) {
            res.status(404).json({ error: 'Pizza not found' });
        } else {
            res.json(pizza);
        }
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};


export const getPizzasByCalories = async (req, res) => {
    try {
        const { calories } = req.query;
        const [caloryOperator, n] = calories.split(" ");

        const match = calories.match(/(\d+)/);

        if (!match) throw new Error("Missing or invalid calories value");

        const num = match[0];
        const matchе = calories.match(/(gt|lt)(\d+)/);
        const caloryOperatore = matchе[1];
        console.log("Число:", caloryOperatore);

        console.log("Число:", num);


        if (!n) throw new Error("Missing calories value");

        const pizzas = (caloryOperatore === 'gt') ?
            await pizzaService.getPizzasByGreaterCalories(num) :
            await pizzaService.getPizzasByLessCalories(num);

        res.json(pizzas);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};

export const postNewPizza = async (req, res) => {
    try {
        const pizzaBody = req.body;
        console.log(pizzaBody)
        const newPizza = await pizzaService.postNewPizza(pizzaBody);

        res.status(201).json(newPizza);
    } catch (error) {
        if (error.message.includes('already exists')) {
            res.status(400).json({ error: 'Pizza with this name already exists' });
        } else {
            res.status(500).json({ error: error.message });
        }
    }
};

export const updatePizzaById = async (req, res) => {
    try {
        const { id } = req.params;

        const pizzaBody = req.body;

        const pizza = await pizzaService.updatePizzaById(id, pizzaBody);

        res.status(201).json(pizza);
    } catch (error) {
        if (error.message.includes('already exists')) {
            res.status(400).json({ error: 'Pizza with this name already exists' });
        } else {
            res.status(500).json({ error: error.message });
        }
    }
};

export const deletePizzaById = async (req, res) => {
    try {
        const { id } = req.params;
        const pizza = await pizzaService.deletePizzaById(id);
        res.status(201).json(pizza);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
};
