#include <stdio.h>
#include <stdlib.h>
int s(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 3;
    }
    
    return 3*s(n-1) - 3*s(n-2) + s(n-3);
}
int main(int argc, const char * argv[]) {
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    
    if(n<0){
        return 1;
    }
    
    if(n == 0 || n == 1){
        printf("%d", n);
        return 0;
    }
    
    int ret = 0;
    ret = s(n);
    printf("%d", ret);
    
    return 0;
}
