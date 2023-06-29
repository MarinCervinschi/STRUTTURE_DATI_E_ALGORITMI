#include <stdio.h>
#include <stdlib.h>
int C(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return C(n/2) + C(n-n/2) + n;
}
int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n<0){
        return 1;
    }
    int ret = 0;
    ret = C(n);
    printf("%d", ret);
    
    return 0;
}
