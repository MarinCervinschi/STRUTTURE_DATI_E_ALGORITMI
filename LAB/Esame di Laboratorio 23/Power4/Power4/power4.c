#include <stdio.h>
#include <stdlib.h>
static void res(int n, int k, int i, int *x){
    if(k == n){
        *x = i;
        return;
    }
    if( k> n){
        *x = -1;
        return;
    }
    res(n, k*4, i +1, x );
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0 || !n){
        return 1;
    }
    if(n == 1){
        printf("4^0 = 1");
        return 0;
    }
    int x = 0;
    res(n, 4, 1, &x);
    if(x == -1){
        printf("!p4");
        return 0;
    }else{
        printf("4^%d = %d", x, n);
    }
    
    return 0;
}
