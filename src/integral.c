double integral(float (*f) (float), float a, float b, float eps2);
    
double integral(float (*f) (float), float a, float b, float eps2) {
    float h = 0.00001;
    int n = (b - a) / h;
    
    double area = 0;
    for (int i = 0; i < n; ++i) {
        area += (double) f(a + (i + 0.5) * h);
    }
    
    area *= h;

    return area;
}
