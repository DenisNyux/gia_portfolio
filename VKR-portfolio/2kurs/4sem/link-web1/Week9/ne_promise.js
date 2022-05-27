const obj = {
    obj1: {
        r: ['z', {b: 1}, {c: ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']}]
    }
};

console.log(obj.obj1.r[2].c[5])


const {obj1:{r:[,,{c:[,,,,,ef]}]}} = obj
console.log(ef)