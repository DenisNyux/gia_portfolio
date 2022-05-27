const concat = require('goss_concat');

const rgb = (r = 255, g = 255, b = 255) => concat('rgb(', r, ', ', g, ', ', b, ')');
const rgb16 = (r = 0xFF, g = 0xFF, b = 0xFF) => concat('#', r.toString(16), g.toString(16), b.toString(16));
console.log(rgb());
console.log(rgb16());
