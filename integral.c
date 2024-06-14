#include <stdio.h>

extern int one(void);

int main(int argc, char* argv[]) {
    int a = one();
    printf("%d", a);
   
    return 0;
}
