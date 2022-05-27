const make_chart = (canvas, data_obj) =>{
    return new Chart(canvas, {
        type: 'line',
        data: {
            labels: data_obj.time,
            datasets: [{
                label: 'Перемещение',
                borderColor: '#c0978d',
                backgroundColor: '#c0978d',
                fill: false,
                data: data_obj.movement
            },
            {
                label: 'Скорость',
                borderColor: '#972426',
                backgroundColor: '#972426',
                fill: false,
                data: data_obj.speed,
            },
            {
                label: 'Ускорение',
                borderColor: '#5d5e62',
                backgroundColor: '#5d5e62',
                fill: false,
                data: data_obj.acceleration
            }
        ]        
        },
        options: {
            scales: {
                yAxes: [{
                    ticks: {
                        beginAtZero: true
                    }
                }]
            }
        }
    });   
}

const canvases = document.querySelectorAll('.plots');
const first_chart = make_chart(canvases[0], data[0]);
const second_chart = make_chart(canvases[1], data[1]);

