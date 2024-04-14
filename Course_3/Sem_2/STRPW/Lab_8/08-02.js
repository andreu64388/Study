const express = require('express');
const jwt = require('jsonwebtoken');
const bodyParser = require('body-parser');
const dotenv = require('dotenv');
const app = express();
const port = 3000;

const allowedUsers = require('./allowedUsers.json');
dotenv.config();

app.use(bodyParser.json());
const generateAccessToken=(user)=> {
    return jwt.sign(user, process.env.ACCESS_TOKEN_SECRET, { expiresIn: '10m' });
}

app.post('/login', (req, res) => {
    const { username, password } = req.body;
    console.log(username, password);
    const user = allowedUsers.find(user => user.username === username && user.password === password);
    if (user) {
        const accessToken = generateAccessToken({ username: user.username });
        res.json({ accessToken: accessToken });
    } else {
        res.status(401).send('Неправильный логин или пароль');
    }
});

const authenticateToken=(req, res, next)=> {
    const authHeader = req.headers['authorization'];
    const token = authHeader && authHeader.split(' ')[1];
    if (token == null) return res.sendStatus(401);

    jwt.verify(token, process.env.ACCESS_TOKEN_SECRET, (err, user) => {
        if (err) return res.sendStatus(403);
        req.user = user;
        next();
    });
}

app.get('/profile', authenticateToken, (req, res) => {
    res.json({ user: req.user });
});

app.all('*', (req, res) => {
    res.status(404).send('404 Not Found');
});


const main = () => {
    try {
        app.listen(port, () => {
            console.log(`Server is listening at http://localhost:${port}`);
        });
    } catch (e) {
        console.error(e);
    }
}

main();
