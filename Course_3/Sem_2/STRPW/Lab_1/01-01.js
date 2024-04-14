import http from "http";

const PORT = 3000;

const app = http.createServer((req, res) => {
    res.writeHead(200, {
        "Content-Type": "text/html"
    });
  res.end("<h1>Hello World</h1>");
});

const main = async () => {
    try{
        await app.listen(PORT);
        console.log(`Server is running on port ${PORT}`);
    }
    catch (err) {
        console.log(`Error: ${err}`);
    }
}

main();