const express = require('express');
const app = express();
const port = 3000;
const hello = require("./services/ms1.js");
const ms = require("./services/ms2.js");

app.use('/', hello);

app.use('/ms', ms)

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});