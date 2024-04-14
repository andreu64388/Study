import http from "http";

const PORT = 5000;

const app = http.createServer((req,res)=>{
    if(req.url==="/api/name" && req.method==="GET"){
        res.writeHead(200,{"Content-type": "text/plain; charset=utf-8"});
        res.end("Коренчук Андрей Васильевич");
    }
    else {
        res.writeHead(404, {"Content-type": "text/html"});
        res.end(`
            <h1>Not Found</h1>
            <a href="/api/name">Go to name page</a>
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
}

main();