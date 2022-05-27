//Метод оптимального исключения


const gaus = (a) => {
    const n = a.length;
    for (let i = 0; i < n; ++i){
        for (let k = i+1; k < n; ++k){
            let aki = a[k][i]/a[i][i];
            for (let j = i; j < n + 1; ++j){
                a[k][j] -= aki * a[i][j]
            };
        };
    };
    const x = new Array(n);
    for (let i = n-1; i >= 0; --i){
        x[i] = a[i][n] / a[i][i];
        for (let c = n - 1; c > i; c = c - 1){
            x[i] = x[i] - a[i][c]*x[c] / a[i][i];                                                                                                    
        };
    };
    // console.log(a)
    return x;
};

module.exports = gaus;