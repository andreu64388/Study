import http from 'http';
import DB from './04-01.js';
import fs from 'fs';
import url from 'url';

const PORT = 5000;
let db = new DB();

db.on('GET', (req, res) => {
    console.log('DB.Get');

    res.setHeader('Content-Type', 'application/json');
    db.select()
        .then(elem =>{
            res.end(JSON.stringify(elem));
        })
})

db.on('POST', (req, res) =>{
    console.log('DB.POST');
    req.on('data', data => {
        let r = JSON.parse(data);
        if(r.BDay == -1){
            res.setHeader('Content-Type', 'application/json');
            db.select(r)
                .then(elem =>{
                    res.end(JSON.stringify(elem));
                })
        }
        else{
            db.insert(r);
            res.setHeader('Content-Type', 'application/json');
            res.end(JSON.stringify(r));
        }
    })
})

db.on('PUT', (req, res)=>{
    console.log('DB.PUT');

    req.on('data', data => {
        let r = JSON.parse(data);
        db.update(r);
        res.setHeader('Content-Type', 'application/json');
        res.end(JSON.stringify(r));
    })
})

db.on('DELETE', (req, res)=>{
    console.log('DB.DELETE');

    req.on('data', data => {
        let r = JSON.parse(data);
        db.delete(r);
        res.setHeader('Content-Type', 'application/json');
        res.end(JSON.stringify(r));
    })
})

 const app = http.createServer(function(req, res) {
    if(url.parse(req.url).pathname === '/'){
        let html = fs.readFile('index.html', (err, html) => {
            res.writeHead(200, {'Content-Type': 'text/html; charset=utf-8'});
            res.end(html);
        })
    }
    else if (url.parse(req.url).pathname ==='/api/db') {
        db.emit(req.method, req, res);
    }

})

const main = async () => {
    try {
        await app.listen(PORT);
        console.log('Server running at http://localhost:'+PORT+'/');
    }
    catch (e) {
        console.log(e);
    }
}

main();