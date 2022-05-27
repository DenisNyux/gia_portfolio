const fetch = require('node-fetch');

(async () => {
    // Getting array of ip`s
    const arr = await fetch('https://kodaktor.ru/j/ips')
        .then(x => x.json());
    // Putting ip`s to other array
    const arr_ip = arr.map((element) => {
        return element.ip;
    });
    // Making an object of ip`s & frequencies 
    // ???
    const table = arr_ip.reduce((acc, el) =>{
        acc[el] = (acc[el] || 0) + 1;
        return acc;
    }, {});
    // Getting frequencies & sorting them
    const freq_s = Object.values(table);
    freq_s.sort((a, b) => b-a);
    // Making a new object, sorted by values 
    let table_sorted = {}
    for (let i = 0; i < freq_s.length; ++i) {
        for (key in table) {
            if (freq_s[i] === table[key]) table_sorted[key] = freq_s[i];
        };
    }
    console.log(table_sorted);
    // Answering questions
    const ip_am = Object.keys(table_sorted).length
    const single_am = freq_s.filter(x => x === 1).length;
    const max_freq = freq_s[0]
    console.log(`
    Всего адресов: ${ip_am}
    Посещался по 1 разу c ${single_am} адресов
    Максимальная частота ${max_freq}
    `);
})()
    