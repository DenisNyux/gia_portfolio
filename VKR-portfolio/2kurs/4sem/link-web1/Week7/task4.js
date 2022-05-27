const arr_gen = require('./arr_gen')

const arr = arr_gen.random();
console.log(`Неотсортированный массив: ${arr}`);
arr.sort((a, b) => a-b);
console.log(`Неотсортированный массив: ${arr}`);
