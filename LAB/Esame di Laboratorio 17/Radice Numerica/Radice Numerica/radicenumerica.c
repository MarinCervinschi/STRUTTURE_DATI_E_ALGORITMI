#include <stdlib.h>
#include <stdio.h>
int Radice(int n){
    int num = 0;
    if(n < 9){
        return n;
    }
    while (n > 0) {
        num += n%10;
        n /= 10;
    }
    return Radice(num);
}
int main(int argc, const char * argv[]) {
    if(argc != 2){
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    
    int ret = 0;
    ret = Radice(n);
    printf("%d", ret);
    
    return 0;
}
