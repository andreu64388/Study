import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

class PizzaService {
    async getAllPizzas() {
        try {
            const pizzas = await prisma.pizzas.findMany();
            return pizzas;
        } catch (error) {
            throw new Error('Unable to fetch pizzas');
        }
    }

    async getPizzasById(id) {
        if (isNaN(id)) {
            throw new Error('Id is not a number');
        }
        try {
            const pizza = await prisma.pizzas.findUnique({
                where: {
                    id: parseInt(id)
                }
            });
            if (!pizza) {
                throw new Error('Pizza with this Id is not found');
            }
            return pizza;
        } catch (error) {
            throw new Error('Unable to find pizzas');
        }
    }

    async getPizzasByGreaterCalories(n) {
        try {
            console.log(n)
            const pizzas = await prisma.pizzas.findMany({
                where: {
                    calories: {
                        gt: parseInt(n)
                    }
                }
            });

            if (!pizzas.length) {
                throw new Error('No pizzas found with calories greater than ' + n);
            }
            return pizzas;
        } catch (error) {
            throw new Error('Unable to find pizzas: ' + error.message);
        }
    }

    async getPizzasByLessCalories(n) {
        console.log(n)
        try {
            const pizzas = await prisma.pizzas.findMany({
                where: {
                    calories: {
                        lt: parseInt(n)
                    }
                }
            });

            if (!pizzas.length) {
                throw new Error('No pizzas found with calories less than ' + n);
            }
            return pizzas;
        } catch (error) {
            throw new Error('Unable to find pizzas: ' + error.message);
        }
    }


    async postNewPizza(data) {
        try {
            if (!data.name || !data.calories) {
                throw new Error("Name and calories are required fields");
            } else if (data.calories > 2000) {
                throw new Error("Calories can not be greater than 2000");
            }

            const  isUsedPizzaName = await prisma.pizzas.findUnique({
                where: {
                    name: data.name
                }
            });

            if (isUsedPizzaName) {
                throw new Error("Pizza with this name already exists");
            }
            const newPizza = await prisma.pizzas.create({
                data: {
                    name: data.name,
                    calories: data.calories,
                    description: data.description
                }
            });
            return newPizza;
        } catch (error) {
            throw new Error('Unable to create new pizza: ' + error.message);
        }
    }


    async updatePizzaById(id, newData) {
        try {
            const  { name, calories,description } = newData;
            console.log(newData);
            if(!name && !calories) {
                throw new Error("Name or calories are required fields");
            }

            if (isNaN(id)) {
                throw new Error("Id is not a number");
            }
            const existingPizza = await prisma.pizzas.findUnique({
                where: {
                    id: parseInt(id)
                }
            });

            console.log(existingPizza);

            if (!existingPizza) {
                throw new Error("Pizza with this id not found")
            }
            const updatedPizza = await prisma.pizzas.update({
                where: {
                    id: parseInt(id)
                },
                data: {
                    name: name,
                    calories: calories,
                    description: description !== undefined ? description : existingPizza.description
                }

            });

            return updatedPizza;
        } catch (error) {
            throw new Error('Unable to update pizza: ' + error.message);
        }
    }

    async updatePizzaHighCalories(id) {
        try {
            if (isNaN(id)) {
                throw new Error("Id is not a number");
            }
            const existingPizza = await prisma.pizzas.findUnique({
                where: {
                    id: parseInt(id)
                }
            });
            if (!existingPizza) {
                throw new Error("Pizza with this id not found")
            }
            const updatedPizza = await prisma.pizzas.update({
                where: {
                    id: parseInt(id)
                },
                data: {
                 description: "High calories"
                }
            });
            return updatedPizza;
        } catch (error) {
            throw new Error('Unable to update pizza: ' + error.message);
        }
    }

    async deletePizzaById(id) {
        try {
            console.log(id)
            if (isNaN(id)) {
                throw new Error("Id is not a number");
            }
            const existingPizza = await prisma.pizzas.findUnique({
                where: {
                    id: parseInt(id)
                }
            });
            if (!existingPizza) {
                throw new Error("Pizza with this id not found")
            }
            await prisma.pizzas.delete({
                where: {
                    id: parseInt(id)
                }
            });
            return existingPizza;
        } catch (error) {
            throw new Error('Unable to delete pizza: ' + error.message);
        }
    }
}

export default new PizzaService();
