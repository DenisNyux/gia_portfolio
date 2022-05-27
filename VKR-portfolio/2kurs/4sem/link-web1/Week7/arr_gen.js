const gen_random = (amount=10, max_el=11) => {
    const arr = Array.from({ length: amount }, (x) => Math.floor(Math.random() * max_el))
    return arr;
}

const gen_ten = (n = 10) => {
    const arr = Array.from({ length: n }, (x, i) => i)
    return arr
}



module.exports.random = gen_random;
module.exports.gen_ten = gen_ten;
