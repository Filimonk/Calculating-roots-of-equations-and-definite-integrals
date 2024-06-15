
/* Объявления ф-ций */

float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float));

float F(float x);

float dF(float x);

float float_abs(float x);

/*==================*/

float (*global_f) (float);
float (*global_g) (float);

float F(float x) {
    return global_f(x) - global_g(x);
}

float (*global_df) (float);
float (*global_dg) (float);

float dF(float x) {
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
           float (*df) (float), float (*dg) (float)) {

    global_f = f;
    global_g = g;

    global_df = df;
    global_dg = dg;

    float c = (a + b) / 2;
    while (F(c) * F(c + eps1) > 0 && F(c - eps1) * F(c) > 0) {
        c = c - F(c) / dF(c);
    }
    
    return c;
}
