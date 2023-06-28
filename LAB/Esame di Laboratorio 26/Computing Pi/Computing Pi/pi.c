#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double π(double n){
    if(n == 0){
        return 4;
    }
    double num = ( 4 * pow(-1, n) )/ (2 * n + 1);
    return num + π(n-1);;
}

int main(int argc, const char * argv[]) {
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    double ret = 0;
    ret = π((double)n);
    
    printf("%f", ret);
    return 0;
}
