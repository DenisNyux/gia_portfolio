const cc = (x = 0) => () => ++x;
console.log(cc(2)(3))