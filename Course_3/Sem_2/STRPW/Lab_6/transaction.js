import { PrismaClient } from '@prisma/client';

const prisma = new PrismaClient();

async function updateHighCaloriePizzas() {
    let transaction;
    try {

        transaction = await prisma.$transaction(async (prisma) => {
            const highCaloriePizzas = await prisma.pizzas.findMany({
                where: {
                    calories: {
                        gt: 1500
                    }
                }
            });


            const modifiedPizzas = highCaloriePizzas.map((pizza) => {
                return prisma.pizzas.update({
                    where: {
                        id: pizza.id
                    },
                    data: {
                        description: `${pizza.description || ''} SUPER FAT!`
                    }
                });
            });


            await Promise.all(modifiedPizzas);
        });

        console.log('Транзакция выполнена успешно');
    } catch (error) {

        if (transaction) {
            await prisma.$queryRaw('ROLLBACK');
        }
        console.error('Ошибка транзакции:', error);
    } finally {

        await prisma.$disconnect();
    }
}

updateHighCaloriePizzas();
