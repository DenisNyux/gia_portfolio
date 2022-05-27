const arr_gen = require('./arr_gen');

const arr = arr_gen.random(10, 50);
console.log(`Массив: ${arr}`);
Array.prototype.max = function () { return Math.max(...this); };
console.log(arr.max())