const compose = (...funcs) => funcs.reduce((accum, fn) => (...args) => accum(fn(...args), x => x));
module.exports.compose = compose