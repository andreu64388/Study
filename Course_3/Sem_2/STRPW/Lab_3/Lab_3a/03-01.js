import http from "http";
import readline from 'readline';

const PORT = 5000;
let state = "norm";


const app = http.createServer((req, res) => {
    if (state != null) {
        res.writeHead(200, { "Content-Type": "text/html; charset=utf-8" });
        res.end(`<h1>${state}</h1>`);
    } else {
        res.end("<h1>Error</h1>");
    }
});


app.listen(PORT, () => {
    console.log("Сервер начал прослушивание запросов на порту 5000");
});

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.setPrompt('Введите новое состояние (norm, stop, test, idle, exit): ');

rl.on('line', (input) => {
    const trimmedInput = input.trim();
    const states = ['norm', 'stop', 'test', 'idle', 'exit'];

    if (states.includes(trimmedInput)) {
        console.log(`${state} -> ${trimmedInput}`);

        if (trimmedInput === 'exit') {
            process.exit(0);
        } else {
            state = trimmedInput;
        }
    } else {
        console.log(`Неизвестный стейт: ${trimmedInput}\n${state} -> ${state}`);
    }

    rl.prompt();
});

rl.prompt();
