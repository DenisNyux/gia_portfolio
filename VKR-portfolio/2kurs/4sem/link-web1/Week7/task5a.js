const summer = (a, b, c) => a + b + c;
console.log(summer.apply(null, [1, 2, 3]));
console.log(summer(...[1, 2, 3]));