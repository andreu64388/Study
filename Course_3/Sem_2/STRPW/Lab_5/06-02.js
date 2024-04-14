import http from 'http';
import fs from 'fs';
import nodemailer from 'nodemailer';

const pass = 'plmp muqj ydze rtkk';
const PORT = 5000;

const  send=(sender, receiver, message)=> {
    let transporter = nodemailer.createTransport({
        service: 'gmail',
        port: 587,
        secure: false,
        auth: {
            user: sender,
            pass: pass
        }
    });

    var mailOptions = {
        from: sender,
        to: receiver,
        subject: 'Lab5',
        text: message,
        html: `<i>${message}</i>`
    };

    transporter.sendMail(mailOptions, function (error, info) {
        if (error) {
            console.error(error);
        } else {
            console.log('Email sent: ' + info.response);
        }
    });
}

const app = http.createServer((req, res) => {
    if (req.method === 'GET') {
        fs.readFile('index.html', (err, data) => {
            if (err) {
                res.writeHead(500);
                res.end('Internal Server Error');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.end(data);
            }
        });
    } else if (req.method === 'POST' && req.url === '/send') {
        let body = '';

        req.on('data', (chunk) => {
            body += chunk;
        });

        req.on('end', () => {
            const formData = new URLSearchParams(body.toString());
            const sender = formData.get('sender');
            const receiver = formData.get('receiver');
            const message = formData.get('message');


            send(sender, receiver, message);

            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end('Email sent!');
        });
    } else {
        res.writeHead(404);
        res.end('Not Found');
    }
})

const main = async () => {
    try {
        await app.listen(PORT);
        console.log(`Server running at http://localhost:${PORT}/`);
    }
    catch (err) {
        console.error(err);
    }
}

main();