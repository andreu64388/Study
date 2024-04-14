import http from "http";
import url from "url";

const PORT = 5000;

const app = http.createServer((req, res) => {
    if (req.url.startsWith("/fact")) {
        const parsedUrl = url.parse(req.url, true);
        const paramK = parsedUrl.query.k;

        res.writeHead(200, { "Content-Type": "application/json; charset=utf-8" });

        if (!paramK) {
            res.end(JSON.stringify({ error: "Parameter 'k' is missing" }));
        } else {
            const factResult = factorial(parseInt(paramK, 10));
            res.end(JSON.stringify({ k: paramK, fact: factResult }));
        }
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
        console.log("Сервер начал прослушивание запросов на порту 5000");
    } catch (err) {
        console.error(err);
    }
};

main();
