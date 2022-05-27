const http = require('http');

http.createServer((req, res)=>{
    res.end(`Its working on ${process.env.PORT}. Env message: ${process.env.MESSAGE}`);
}).listen(process.env.PORT || 8080, ()=>{console.log(`I am on ${process.env.PORT} port`)});
