#include <stdio.h>

float f(float x);
float df(float x);


extern float f1(float x);
extern float f2(float x);
extern float f3(float x);

extern float df1(float x);
extern float df2(float x);
extern float df3(float x);

float f(float x) { // функция f(x) = 0 и ее производная df(x) = 0
    return 0;
}

float df(float x) {
    return 0;
}



float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float));

double integral(float (*f) (float), float a, float b, float eps2);

int main(int argc, char* argv[]) {
    float x1 = root(f1, f3, 0, 1, 0.00001, df1, df3);
    float x2 = root(f3, f2, 3, 4, 0.00001, df3, df2);
    float x3 = root(f2, f, 2.5, 3.5, 0.00001, df2, df);
    
    printf("%f %f %f\n", x1, x2, x3);
    
    double a = integral(f1, 0, x1, 0.00001);
    double b = integral(f3, x1, x2, 0.00001);
    double c = integral(f2, x3, x2, 0.00001);
    
    printf("%f %f %f %f\n", a, b, c, a + b - c);
   
    return 0;
}
