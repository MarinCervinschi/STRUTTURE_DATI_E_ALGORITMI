#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void Felice(int n, bool *k){
    int len =0 ;
    for (int i = 0, j = n; i != j; ) {
        j /= 10;
        len++;
    }
    if(n == 1){
        return ;
    }
    if(n == 4){
        *k = false;
        return;
    }
    int num = 0;
    for (int i = 0; i != len; ++i) {
        int h = n%10;
        num += n%10 *h;
        n /= 10;
    }
    n = num;
    Felice(n, k);
    
}
int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    if(n == 0){
        printf("Infelice");
        return 0;
    }
    bool k = true;
    Felice(n, &k);
    if(k){
        printf("Felice");
    }else{
        printf("Infelice");
    }
    
    return 0;
}
