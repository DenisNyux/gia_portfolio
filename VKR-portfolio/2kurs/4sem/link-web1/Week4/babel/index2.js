function xor(x, y) {
  return x && !y || !x && y;
};
console.log(xor(1, 0)); // true
