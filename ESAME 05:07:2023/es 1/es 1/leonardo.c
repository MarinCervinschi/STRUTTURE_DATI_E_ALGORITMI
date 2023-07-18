#include <stdio.h>
#include <stdlib.h>
int L(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    return L(n-1) + L(n-2) + 1;
}
int main(int argc, const char * argv[]) {
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    
    for (int i = 0; i < n+1; ++i) {
        printf("%d, ", L(i));
    }
    
    return 0;
}
