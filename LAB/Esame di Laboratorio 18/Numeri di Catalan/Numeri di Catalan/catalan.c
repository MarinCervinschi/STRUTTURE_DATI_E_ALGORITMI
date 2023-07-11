#include <stdio.h>
#include <stdlib.h>

long long int C(int n){
    if(n == 0){
        return 1;
    }
    long long int ret = 0;
    for (int i = 0; i != n; ++i) {
        ret += C( i ) * C(n - 1 - i);
    }
    return ret ;
}

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    long long int ret = 0;
    ret = C(n);
    
    printf("%lld", ret);
    
    return 0;
}
