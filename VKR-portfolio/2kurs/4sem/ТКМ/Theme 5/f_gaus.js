// Метод последовательного исключения

const matrix = [[5, 7, 6, 5, 23],
                [7, 10, 8, 7, 32],
                [6, 8, 10, 9, 33],
                [5, 7, 9, 10, 31]];

const gaus = (a) => {
    const n = a.length;
    for (let i = 0; i < n; ++i){
        const q = a[i][i];
        for (let j = 0; j < n+1; ++j){
            a[i][j] /= q;
        };
        for (let k = i + 1; k < n; ++k){
            const q2 = a[k][i];
            for (let j = i; j < n + 1; ++j){
                a[k][j] -= a[i][j]*q2; 
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
    // console.log(a);
    return x;
};

const sol = gaus(matrix);

console.log(`Solution 1: ${sol}`);