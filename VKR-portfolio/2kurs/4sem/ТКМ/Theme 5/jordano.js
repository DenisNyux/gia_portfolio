// Метод Гаусса - Жордано

const matrix = [[5, 7, 6, 5, 23],
                [7, 10, 8, 7, 32],
                [6, 8, 10, 9, 33],
                [5, 7, 9, 10, 31]];

const gaus = (a) => {
    const n = a.length;
    let aki;
    for (let i = 0; i < n; ++i){
        for (let k = i+1; k < n; ++k){
            if (k!==i){ 
                aki = a[k][i]/a[i][i];
                for (let j = i; j < n + 1; ++j){
                    if (j === i)
                        a[k][j] = 0;
                    else 
                        a[k][j] -= aki * a[i][j];
                };
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

const sol = gaus(matrix);

console.log(`Solution 1: ${sol}`);