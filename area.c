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
    float a = root(f1, f3, 0, 1, 0.0001, df1, df3);
    printf("%f\n", a);
    
    float b = integral(f2, 3, 4, 0.001);
    printf("%f\n", b);
   
    return 0;
}
