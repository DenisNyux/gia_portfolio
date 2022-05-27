const arr_gen = require('./arr_gen');

const letters = arr_gen.gen_ten(10).map((x) => String.fromCharCode(x+65));
console.log(letters);

module.exports.letters = letters;