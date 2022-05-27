const func = (...args) => args.reduce((acc, el) => acc + el);
console.log(func(1, 2, 3, 4, 5));
console.log(func(1, 2, 3, 4));
console.log(func(1, 2));