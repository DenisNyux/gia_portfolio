const pause = require('goss_pause')

console.time('g');
pause(15000) || console.timeEnd('g');

console.time('f');
setTimeout(() => {
    console.log('it passed 15 seconds')
}, 15000) || console.timeEnd('f');