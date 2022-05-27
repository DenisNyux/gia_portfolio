const compose_exp = require('./func4_exp')

const qv = x => x * x;
const sc = x => x + 1;
//console.log(qv(sc((5))));
//console.log(sc(qv((5))));
console.log(compose_exp.compose(qv, sc)(5))
console.log(compose_exp.compose(sc, qv)(5))