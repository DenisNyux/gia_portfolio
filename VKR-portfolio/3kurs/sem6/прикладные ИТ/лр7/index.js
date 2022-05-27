const express = require('express');
const app = express();
const port = 8081;
const path = require('path');
const session = require('express-session');

const passport = require('passport');
const YandexStrategy = require('passport-yandex').Strategy;
const VKStrategy = require('passport-vkontakte').Strategy;

app.use(session({ secret: "supersecret", resave: true, saveUninitialized: true }));

let Users = [{'login': 'admin', 'email':'Aks-fam@yandex.ru'},
            {'login': 'local_js_god', 'email':'ilia-gossoudarev@yandex.ru'},
            {'login': 'DenisNyux', 'email':'denis.nyuxaloff@yandex.ru'}];

const findUserByLogin = (login) => {
    return Users.find((element)=> {
        return element.login == login;
    })
}

const findUserByEmail = (email) => {
    return Users.find((element)=> {
        return element.email.toLowerCase() == email.toLowerCase();
    })
}

app.use(passport.initialize());
app.use(passport.session());


passport.serializeUser((user, done) => {
    done(null, user);
  });
  //user - объект, который Passport создает в req.user

passport.deserializeUser((obj, done) => {
    done(null, obj);
});

passport.use(new YandexStrategy({
    clientID: '65cd8d06f160495d82785e033f46994b',
    clientSecret: '5232308e671b40a3a475f05c5697881a',
    callbackURL: "http://localhost:8081/auth/yandex/callback"
  },
  (accessToken, refreshToken, profile, done) => {
    let user = findUserByEmail(profile.emails[0].value);
    user.profile = profile;
    if (user) return done(null, user);

    done(true, null);
  }
));

passport.use(
    new VKStrategy({
        clientID: '7895345',
        clientSecret: 'x6N0BEFlcsvXOp66ArEM',
        callbackURL: 'http://localhost:8081/auth/vkontakte/callback'
    },
    function verify(accessToken, refreshToken, parems, profile, done) {
        process.nextTick(()=>{
            return done(null, profile);
        });
    }
    )
);

const isAuth = (req, res, next)=> {
    if (req.isAuthenticated()) return next();

    res.redirect('/sorry');
}


app.get('/', (req, res)=> {
    res.sendFile(path.join(__dirname, 'main.html'));
});
app.get('/sorry', (req, res)=> {
    res.sendFile(path.join(__dirname, 'sorry.html'));
});
app.get('/auth/yandex', passport.authenticate('yandex'));

app.get('/auth/yandex/callback', passport.authenticate('yandex', { failureRedirect: '/sorry', successRedirect: '/private' }));

app.get('/auth/vkontakte', passport.authenticate('vkontakte'));

app.get(
    '/auth/vkontakte/callback',
    passport.authenticate('vkontakte', {
        successRedirect: '/private',
        failureRedirect: '/sorry'
    })
);

app.get('/private', isAuth, (req, res)=>{
    res.send(req.user);
});



app.listen(port, () => console.log(`App listening on port ${port}!`))