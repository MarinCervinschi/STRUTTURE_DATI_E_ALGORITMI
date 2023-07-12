#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool IsPrime(int n ,int div){
    if(div == 10 || div >= n){
        return true;
    }
    if(n % div == 0){
        return false;
    }
    
    return IsPrime(n, div +1);
}
int main(int argc, const char * argv[]) {
    if (argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    if(n < 2){
        printf("false");
        return 0;
    }
    IsPrime(n, 2) ? printf("true") : printf("false");
    
    return 0;
}
