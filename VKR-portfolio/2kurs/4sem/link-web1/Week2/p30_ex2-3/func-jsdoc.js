/** @const {string} */ const hiWord = 'Hello';

/**
* Возвращает приветсвие
* принимает строку или ничто, в случае ничто выполняет безымянное приветсвие
*/
function sayHello(name = 'Nameless') {
  return `${hiWord}, ${name}!`;
}
console.log(sayHello('Denis'));
console.log(sayHello());
