import http from 'http';
import fs from 'fs';

const PORT = 5000;

const app = http.createServer((req, res) => {

    if (req.url === "/xmlhttprequest") {
        fs.readFile("xmlhttprequest.html", (err, data) => {
            if (err) {
                res.writeHead(500, { "Content-Type": "text/plain" });
                res.end("Internal Server Error");
            } else {
                res.writeHead(200, {"Content-Type": "text/html; charset=utf-8" });
                res.end(data);
            }
        });
    }  else if (req.url === "/api/name") {
        res.writeHead(200, {'Content-Type': 'text/plain; charset=utf-8'});
        res.end('Коренчук Андрей Васильевич');

    }
    else {
        res.writeHead(404, { "Content-Type": "text/html" });
        res.end(`
            <h1>Not Found</h1>
            <a href="/xmlhttprequest">Go to XMLHttpRequest page</a>
        `);
    }
})

const main = async () => {
    try {
        await app.listen(PORT);
        console.log(`Server is running on port ${PORT}`);
    } catch (e) {
        console.error(e);
    }
};

main();
