#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
           float (*df) (float), float (*dg) (float), bool iteration_Flag);

double integral(float (*f) (float), float a, float b, float eps2);

int main(int argc, char* argv[]) {
    if (argc == 1) {
        float x1 = root(f1, f3, 0, 1, 0.00001, df1, df3, false);
        float x2 = root(f3, f2, 3, 4, 0.00001, df3, df2, false);
        float x3 = root(f2, f, 2.5, 3.5, 0.00001, df2, df, false);
        
        double term1 = integral(f1, 0, x1, 0.00001);
        double term2 = integral(f3, x1, x2, 0.00001);
        double term3 = integral(f2, x3, x2, 0.00001);
        
        printf("площадь заданной фигуры = %.3f + %.3f - %.3f = %.3f\n", term1, term2, term3, term1 + term2 - term3);
        
        return 0;
    }
   
    // Будем обрабатывать только один ключ (по заданию так можно делать)
    char *key = argv[1];
    int first_Letter_Ind = 0;
    while (key[first_Letter_Ind] == '-') {
        ++first_Letter_Ind;
    }
    
    char first_Letter = key[first_Letter_Ind];
    if (first_Letter == 'h') {
        printf("--help или -h - выводят на печать все допустимые ключи командной строки\n");
        printf("--root и -r - печатают абсциссы точек пересечения кривых\n");
        printf("--iterations и -i - печатают число итераций, потребовавшихся на приближенное решение уравнений при поиске точек пересечения");
        printf("--test-root и -R - позволяют протестировать функцию root\n");
        printf("--test-integral и -I - позволяют протестировать функцию integral\n");
    }
    else if (first_Letter == 'r') {
        float x1 = root(f1, f3, 0, 1, 0.00001, df1, df3, false);
        float x2 = root(f3, f2, 3, 4, 0.00001, df3, df2, false);
        
        printf("%.3f - абсцисса пересечения 1 и 3, %.3f - абсцисса пересечения 3 и 2\n", x1, x2);
    }
    else if (first_Letter == 'i') {
        float iterations1 = root(f1, f3, 0, 1, 0.00001, df1, df3, true);
        float iterations2 = root(f3, f2, 3, 4, 0.00001, df3, df2, true);

        printf("колличество итераций, потребовавшихся на приближенное решение уравнений при поиске точек пересечения = %.3f + %.3f = %.3f\n", iterations1, iterations2, iterations1 + iterations2);
    }
    else if ((first_Letter == 't' && key[7] == 'r') || first_Letter == 'R') {
        printf("5");
    }
    else if ((first_Letter == 't' && key[7] == 'i') || first_Letter == 'I') {
        printf("5");
    }
    
    return 0;
}
