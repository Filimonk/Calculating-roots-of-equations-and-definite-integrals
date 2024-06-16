#include <stdbool.h>

/* Объявления ф-ций */

float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float), bool iteration_Flag);

float F(float x);

float dF(float x);

float float_abs(float x);

/*==================*/

float (*global_f) (float);  // в global_ функции мы копируем ф-ии, которые передали в root
float (*global_g) (float);

float F(float x) {      // F(x) = f(x) - g(x), где f и g из root
    return global_f(x) - global_g(x);
}

float (*global_df) (float); // в global_ функции мы копируем ф-ии, которые передали в root
float (*global_dg) (float);

float dF(float x) {     // dF(x) = d(f(x) - g(x)), где f и g из root
    return global_df(x) - global_dg(x);
}

float float_abs(float x) {
    if (x < 0) {
        return -x;
    }
    
    return x;
}

float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float), bool iteration_Flag) {

    global_f = f;
    global_g = g;

    global_df = df;
    global_dg = dg;

    float iterations = 0;
    float c = (a + b) / 2;
    while (F(c) * F(c + eps1) > 0 && F(c - eps1) * F(c) > 0) {
        c = c - F(c) / dF(c);
        iterations += 1;
    }
    
    if (iteration_Flag) {
        return iterations;
    }
    
    return c;
}
