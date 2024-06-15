#include <stdio.h>

extern float f1(float x);
extern float f2(float x);
extern float f3(float x);

extern float df1(float x);
extern float df2(float x);
extern float df3(float x);



float root(float (*f) (float), float (*g) (float), 
           float a, float b, float eps1,
           float (*df) (float), float (*dg) (float));

float integral(float (*f) (float), float a, float b, float eps2);

int main(int argc, char* argv[]) {
    printf("%f %f %f\n", f1(1), f2(1.5), f3(1.5));
    printf("%f %f %f\n", df1(1.5), df2(1.5), df3(1.5));
    
    float a = integral(f1, 0, 1, 0.001);
    printf("%.3f\n", a);
   
    return 0;
}
