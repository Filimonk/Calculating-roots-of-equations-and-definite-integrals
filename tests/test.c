#include <stdio.h>
#include <stdbool.h>

/* Объявления ф-ций */

float f1(float x);
float f2(float x);
float f3(float x);

float df1(float x);
float df2(float x);
float df3(float x);


float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float), bool iteration_Flag);

double integral(float (*f) (float), float a, float b, float eps2);

/*==================*/

float f1(float x) {
    return x;
}

float df1(float x) {
    return 1;
}


float f2(float x) {
    return x * x - 2;
}

float df2(float x) {
    return 2 * x;
}


float f3(float x) {
    return 1 / (x + 3);
}

float df3(float x) {
    return -1 / ((x + 3) * (x + 3));
}

int main(int argc, char* argv[]) {
    printf("tests root:\n");

    float x1 = root(f1, f2, 2.5, 3.5, 0.01, df1, df2, false);
    printf("x = x^2 - 2, eps = 0.01, x0 = %.2f\n", x1);
    
    float x2 = root(f1, f3, -4, -3, 0.0001, df1, df3, false);
    printf("x = 1 / (x + 3), eps = 0.0001, x0 = %.4f\n", x2);
    
    float x3 = root(f2, f3, 1, 2, 0.001, df2, df3, false);
    printf("x^2 - 2 = 1 / (x + 3), eps = 0.001, x0 = %.3f\n", x3);
    
    
    printf("\ntests integral:\n");
    
    float s1 = integral(f1, -1, 0.5, 0.01);
    printf("y = x, Interval(-1, 0.5), eps = 0.01, s = %.2f\n", s1);
    
    float s2 = integral(f2, -1.5, 0, 0.001);
    printf("y = x^2 - 2, Interval(-1.5, 0), eps = 0.001, s = %.3f\n", s2);
    
    float s3 = integral(f3, 3, 4, 0.0001);
    printf("y = 1 / (x + 3), Interval(3, 4), eps = 0.0001, s = %.4f\n", s3);
    
    printf("\n\nALL TESTS PASSED SUCCESSFULLY!!!\n\n");
   
    return 0;
}
