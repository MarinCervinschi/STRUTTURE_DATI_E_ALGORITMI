#include <stdio.h>
#include <stdlib.h>
#include <math.h>
unsigned long fattoriale(unsigned long n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fattoriale(n-1);
}
double sin_xRec(int i, double x, double count){
    if((int)count == i){
        return 0;
    }
    return sin_xRec(i, x, count + 1) + ((pow((-1), count)) / fattoriale(2*count+1)) * pow(x, 2*count+1);
}
int main(int argc, const char * argv[]) {
    if(argc != 3){
        return 1;
    }
    int i = atoi(argv[2]);
    if(i < 0){
        return 1;
    }
    double x = atof(argv[1]);
    
    double sinX = 0;
    
    sinX = sin_xRec(i+1, x, 0);
    
    printf("%f", sinX);
    
    return 0;
}
