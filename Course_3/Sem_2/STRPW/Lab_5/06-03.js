import { send } from "./m06_KAV.js"

const from = 'andrysa.shev.133@gmail.com';
const to = 'anton.demenkoves7@gmail.com\n';
const pass = 'plmp muqj ydze rtkk';
let message = 'Hello from 05-03!';

async function main() {
    try {
        await send(from, to, pass, message);
        console.log('Функция send успешно выполнена');
    } catch (error) {
        console.error('Произошла ошибка при выполнении функции send:', error);
    }
}

main();
