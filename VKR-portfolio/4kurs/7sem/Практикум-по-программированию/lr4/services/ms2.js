const express = require('express');
const app = express();
const port = 3001;

app.post('/ms', (req, res) => {
    res.json({res: "New ms!", num: 14});
});

app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});