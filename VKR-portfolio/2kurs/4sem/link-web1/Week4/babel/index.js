// @flow
function xor(x: boolean, y: boolean): boolean {
    return (x && !y) || (!x && y)
    };
console.log(xor(1, 0)); // true