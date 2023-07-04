#include <stdio.h>
#include <stdlib.h>

double MappaLog(double x, double r, int n) {
    if (n == 0) {
        return x;
    }
    
    double previousValue = MappaLog(x, r, n - 1);
    return r * previousValue * (1 - previousValue);
}

int main(int argc, const char * argv[]) {
    if (argc != 4) {
        return 1;
    }
    
    double x0 = atof(argv[1]);
    double r = atof(argv[2]);
    int n = atoi(argv[3]);
    
    if (x0 < 0 || x0 > 1 || r < 0 || n < 0) {
        return 1;
    }
    
    double res = MappaLog(x0, r, n);
    printf("%f", res);
    
    return 0;
}
