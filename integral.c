#include <stdio.h>

extern float f1(float x);
extern float f2(float x);
extern float f3(float x);

int main(int argc, char* argv[]) {
    printf("%f %f %f\n", f1(2), f2(2), f3(2));
   
    return 0;
}
