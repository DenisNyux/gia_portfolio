const moment = require('moment');
const faker = require('faker');

const newPre = document.createElement('pre');
document.body.appendChild(newPre);
newPre.textContent += 'привет';
newPre.textContent += '\n';
newPre.textContent += 'снова привет';
newPre.textContent += '\n';
newPre.textContent += moment().format('DD.MM.YYYY HH:mm:ss\n');

const h4 = document.createElement('h4');
document.body.appendChild(h4);
h4.setAttribute('title', 'GossJS')
h4.setAttribute('id', 'author')
h4.textContent += 'Nyukhalov Denis'
