import http from "http";
import fs from "fs";
import url from 'url';

const PORT = 5000;

const app = http.createServer((req, res) => {

    let path = url.parse(req.url, true);

    if (path.pathname === '/fact') {
        const k = +path.query.k;

        if (Number.isInteger(k) && k >= 0) {
            res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8' });

            setImmediate(() => {
                res.end(JSON.stringify({k: k, fact: factorial(k)}));
            });

        } else {
            res.writeHead(400, { 'Content-Type': 'text/plain; charset=utf-8' });
            res.end("Неверный параметр K");
        }
    } else if (path.pathname === '/') {
        fs.readFile('index.html', 'utf-8', function (err, data) {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
                res.end("Ошибка сервера");
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
                res.end(data);
            }
        });
    } else {
        res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end("Страница не найдена");
    }
});

const factorial = (k) => {
    if (k === 0) {
        return 1;
    } else {
        return k * factorial(k - 1);
    }
};


const main = async () => {
    try {
        app.listen(PORT);
        console.log(`Сервер начал прослушивание запросов на порту ${PORT}`);
    } catch (err) {
        console.error(err);
    }
};

main();