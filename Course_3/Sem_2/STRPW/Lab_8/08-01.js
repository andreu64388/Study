const express = require('express');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const flash = require('connect-flash');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

const allowedUsers = require('./allowedUsers.json');

app.use(session({
    secret: 'secret',
    resave: false,
    saveUninitialized: true
}));

app.use(passport.initialize());
app.use(passport.session());
app.use(flash());

app.use(bodyParser.urlencoded({ extended: false }));

passport.use(new LocalStrategy(
    (username, password, done)=> {
        const user = allowedUsers.find(user => user.username === username && user.password === password);
        if (user) {
            return done(null, user);
        } else {
            return done(null, false, { message: 'Incorrect username or password' });
        }
    }
));

passport.serializeUser((user, done)=> {
    done(null, user.id);
});

passport.deserializeUser((id, done)=> {
    const user = allowedUsers.find(user => user.id === id);
    done(null, user);
});


app.get('/login', (req, res)=> {
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

app.post('/login',
    passport.authenticate('local', {
        successRedirect: '/profile',
        failureRedirect: '/login',
        failureFlash: true
    })
);


app.get('/logout', (req, res)=> {
    req.logout((err)=> {
        if (err) {
            return next(err);
        }
        res.redirect('/');
    });
});


app.get('/profile', (req, res)=> {
    if (req.isAuthenticated()) {
        res.send('Authenticated User: ' + JSON.stringify(req.user));
    } else {
        res.redirect('/login');
    }
});


app.all('*', (req, res)=> {
    res.status(404).send('404 Not Found');
});


const main =  () =>{
    try {
        app.listen(port, () => {
            console.log(`Server is listening at http://localhost:${port}`);
        });
    }
    catch (e) {
        console.log(e);
    }
}

main()