import http from 'http';
import fs from 'fs';


const PORT = 5000;

const app = http.createServer((req, res) => {
    if (req.url === "/html" && req.method === "GET") {
        return readFileAndSendResponse(res, "index.html", "text/html");
    }

    res.writeHead(404, { "Content-type": "text/html" });
    res.end(`
        <h1>Not Found</h1>
        <a href="/html">Go to HTML page</a>
    `);
});

function readFileAndSendResponse(res, fileName, contentType) {
    fs.readFile(fileName, "utf8", (err, data) => {
        if (err) {
            res.writeHead(500, { "Content-type": "text/plain" });
            res.end("Internal Server Error");
        } else {
            res.writeHead(200, { "Content-type": contentType });
            res.end(data);
        }
    });
}



const main = async () => {
    try {
        await app.listen(PORT);
        console.log(`Server is running on port ${PORT}`);
    } catch (e) {
        console.error(e);
    }
};

main();
