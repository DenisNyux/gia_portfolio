const curryPow = x => y => x ** y;
const partiPow = x => y => x
console.log(curryPow(2)(3)); 
console.log(partiPow(3))
