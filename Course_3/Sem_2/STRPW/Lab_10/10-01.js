const express = require('express');
const jwt = require('jsonwebtoken');
const bodyParser = require('body-parser');
const dotenv = require('dotenv');
const userRouter = require('./routers/user.router');
const reposRouter = require('./routers/repos.router');
const { PrismaClient } = require('@prisma/client');
const prisma = new PrismaClient();
const app = express();

const PORT = 3000;
dotenv.config();

app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

const generateAccessToken=(user)=> {
  return jwt.sign(user, 'secret', { expiresIn: '10m' });
}

const authenticateToken = (req, res, next) => {
  const authHeader = req.headers['authorization'];
  const token = authHeader && authHeader.split(' ')[1];
  console.log(token)
  if (token == null) return res.sendStatus(401);

  jwt.verify(token, "secret", (err, user) => {
    if (err) return res.sendStatus(403);
    req.user = user;

    const allowedRoutes = {
      admin: ['/api/repos', '/logout', '/profile'],
      user: ['/api/user', '/logout', '/profile'],
      guest: ['/login', '/register']
    };

    console.log(user)
    console.log(req.originalUrl);

    if (!allowedRoutes[user.role].includes(req.originalUrl)) {
      return res.status(403).send('Доступ запрещен');
    }

    next();
  });
}

app.use("/api/user",authenticateToken, userRouter);
app.use("/api/repos",authenticateToken, reposRouter);

app.get("/register", (req, res) => {
  res.send(`
        <form action="/register" method="post">
            <div>
                <label for="username">Username:</label>
                <input type="text" id="username" name="username">
            </div>
            <div>
                <label for="password">Password:</label>
                <input type="password" id="password" name="password">
            </div>
            <div>
                <input type="submit" value="Register">
            </div>
        </form>
    `);
});

app.post('/register', async (req, res) => {
  try {
    const { username, password } = req.body;
    if (!username || !password) {
      return res.status(400).send('Не указаны все необходимые данные для регистрации');
    }

    const user = await prisma.users.findUnique({ where: { username: username } });

    if (user) {
      return res.status(400).send('Пользователь с таким именем уже существует');
    } else {
      await prisma.users.create({
        data: {
          username: username,
          password: password,
          role: "user"
        }
      });
      const token = generateAccessToken(user);
      return res.status(201).send('Пользователь успешно создан' + token);
    }
  } catch (e) {
    console.log(e);
    return res.status(500).send(e.message);
  }
});

app.get('/login', (req, res) => {
  res.send(`<form action="/login" method="post">
            <div>
        <label>Username:</label>
        <input type="text" name="username">
            </div>
             <div>
        <label>Password:</label>
        <input type="password" name="password">
            </div>
        <div>
        <input type="submit" value="Log In"></div>
        </form>`);
});

app.post('/login', async (req, res) => {
  const { username, password } = req.body;
  const user = await prisma.users.findUnique({ where: { username: username } });
  if (user && user.password === password) {
    const token = generateAccessToken(user);
    res.send('Вы успешно вошли в систему ' + token);
  } else {
    res.status(401).send('Неправильный логин или пароль');
  }
});

app.get('/profile',authenticateToken, (req, res) => {
  res.json({ user: req.user });
});

app.get('/logout', (req, res) => {
  res.send('Вы успешно вышли из системы');
});

app.all('*', (req, res) => {
  res.status(404).send('404 Not Found');
});

const main = () => {
  try {
    app.listen(PORT, () => {
      console.log(`Server is listening at http://localhost:${PORT}`);
    });
  } catch (e) {
    console.error(e);
  }
}

main();
