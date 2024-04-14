import http from "http";
import url from "url";
import fs from "fs";

const PORT = 5000;

const app = http.createServer((req, res) => {
    const parsedUrl = url.parse(req.url, true);
    const pathname = parsedUrl.pathname;

    if (pathname.startsWith("/fact")) {
        const paramK = parsedUrl.query.k;

        res.writeHead(200, { "Content-Type": "application/json; charset=utf-8" });

        if (!paramK) {
            res.end(JSON.stringify({ error: "Parameter 'k' is missing" }));
        } else {
            const factResult = factorial(parseInt(paramK, 10));
            res.end(JSON.stringify({ k: paramK, fact: factResult }));
        }
    }
    else if (pathname === "/") {

        fs.readFile("index.html", "utf8", function (err, data) {
            if (err) {
                res.writeHead(500, { "Content-Type": "text/plain" });
                res.end("Internal Server Error");
            } else {
                res.writeHead(200, { "Content-Type": "text/html; charset=utf-8" });
                res.end(data);
            }
        });
    } else {
        res.writeHead(404, { "Content-Type": "text/html" });
        res.end(`<h1>Not Found</h1><p>Unknown URL: ${pathname}</p>`);
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
