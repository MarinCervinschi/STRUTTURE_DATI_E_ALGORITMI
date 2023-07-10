#include <stdio.h>
#include <stdlib.h>
int S(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    int num1 = ( (6*n - 3) * S(n-1) ) / (n+1);
    int num2 = ( (n - 2) * S(n-2) ) / (n+1);
    return num1- num2;
}
int main(int argc, const char * argv[]) {
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n<0){
        return 1;
    }
    
    int ret = S(n);
    
    printf("%d", ret);
    
    return 0;
}
