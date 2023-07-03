#include <stdio.h>
#include <stdlib.h>

double Concentrazione(int n){
    if(n == 0){
        return 0;
    }
    return (Concentrazione(n-1) * 0.3) + 0.2;
}
int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 1){
        return 1;
    }
    
    double ret= 0;
    ret = Concentrazione(n-1);
    
    printf("%f", ret);
    
    return 0;
}
