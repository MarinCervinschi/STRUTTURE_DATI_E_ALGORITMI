#include <stdio.h>
#include <stdlib.h>
void Bin(int n){
    if(n == 0){
        return;
    }
    Bin(n/2);
    n % 2 == 0 ? printf("0") : printf("1");
}
int main(int argc, const char * argv[]) {
    if( argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    if (n == 0) {
        printf("0");
        return 0;
    }
    Bin(n);
    return 0;
}
