function cacheIm(url){
    const im = document.createElement('img');
    im.src = url;
    im.style.display = 'none'
    return im;
};

img_arr = [
    'https://beginpc.ru/images/internet/js_logo.jpg',
    'https://cdn.pixabay.com/photo/2015/04/23/17/41/javascript-736401_960_720.png',
    'http://w3.org.ua/wp-content/uploads/2017/01/icon.javascript.png'
];

document.getElementById('l')
    .addEventListener('click', ev => {
        img_arr.forEach(element => {
            document.body.appendChild(cacheIm(element))
        });
        ev.target.style.display = 'none';        
})

document.getElementById('i')
    .addEventListener('click', ev => {
        images = document.querySelectorAll('img');
        images.forEach(element => {
            element.style.display = 'flex'
            element.addEventListener('click', ({target}) => {
                target.style = 'border: 10px solid aquamarine';
            })
        });
})