const randint = (min=10, max=10000000) => {
    const rand = Math.floor(min + Math.random() * (max - min));
    return rand;
} 

const generate = (length = 10) => {
    const arr = Array
    .from({ length: length }, (x) => randint())
    .map(x => String(x).padStart(10, '0'));
    return arr;
}


const arr = generate();
console.log(arr)