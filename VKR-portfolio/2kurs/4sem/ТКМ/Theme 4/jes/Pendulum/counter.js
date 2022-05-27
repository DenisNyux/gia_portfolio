// First task
const first_counter = (mass = 0.1, time = 11, elasticity = 0.2, xh = 0.2, am_of_iterations = 11) =>{
    t_arr = new Array(am_of_iterations); 
    x_arr = new Array(am_of_iterations);
    v_arr = new Array(am_of_iterations); 
    a_arr = new Array(am_of_iterations);

    for (let i = 0; i < am_of_iterations; ++i) {
        t_arr[i] = i; 
        t_arr[i] *= time/am_of_iterations;
        x_arr[i] = xh*Math.cos(Math.sqrt(elasticity/mass)*t_arr[i]);
        v_arr[i] = xh*Math.sqrt(elasticity/mass)*Math.cos(Math.sqrt(elasticity/mass)*t_arr[i]+Math.PI/2);
        a_arr[i] = xh*elasticity/mass*Math.cos(Math.sqrt(elasticity/mass)*t_arr[i]+Math.PI);
    };
    return {
            time: t_arr,
            movement: x_arr,
            speed: v_arr,
            acceleration: a_arr
        };
};

// Second task
const second_counter = (t_0 = 0, x_0 = 0.2, v_0 = 0, elasticity = 0.2, mass = 0.1, am_of_iterations = 11, dt = 1) =>{
    t_arr = new Array(am_of_iterations);
    x_arr = new Array(am_of_iterations);
    v_arr = new Array(am_of_iterations);
    a_arr = new Array(am_of_iterations);

    t_arr[0] = t_0;
    x_arr[0] = x_0;
    v_arr[0] = v_0;
    a_arr[0] = -elasticity * x_0 / mass;

    for (let i = 1; i < am_of_iterations; ++i) {
        t_arr[i] = t_arr[i-1] + dt;
        x_arr[i] = x_arr[i-1] + v_arr[i-1];
        v_arr[i] = v_arr[i-1] + a_arr[i-1]*dt;
        a_arr[i] = -elasticity * x_arr[i-1] / mass;
    };
    return {
            time: t_arr,
            movement: x_arr,
            speed: v_arr,
            acceleration: a_arr
        };
};

data = [first_counter(), second_counter()]
console.log(data[1])
