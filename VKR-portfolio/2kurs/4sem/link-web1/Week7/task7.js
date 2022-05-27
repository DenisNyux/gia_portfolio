const sum = (...nums) => nums.reduce((x, y) => x+y);

console.log(`Сумма: ${sum(3, 1, 4, 5)}`)
console.log(`Сумма: ${sum(3, 1, 4)}`)
console.log(`Сумма: ${sum(3, 1)}`)