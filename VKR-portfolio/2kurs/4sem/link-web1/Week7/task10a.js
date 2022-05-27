const arr_gen = require('./arr_gen');

const letters = arr_gen.gen_ten(10).map((x) => String.fromCharCode(x+65));
const numbers = letters.map((x) => x.charCodeAt(0));
console.log(numbers);