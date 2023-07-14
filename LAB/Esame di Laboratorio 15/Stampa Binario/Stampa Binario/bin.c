#include <stdio.h>
#include <stdlib.h>
void Bin(int n, int *v, int index){
    if(n == 0){
        return;
    }
    if( n % 2 != 0){
        v[index] = 1;
    }
    Bin(n/2, v, index + 1);
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
    int count = 0, m = n;
    while (m > 0) {
        m /= 2;
        ++count;
    }
    int *v = calloc(count, sizeof(int));
    
    Bin(n, v, 0);
    
    for (int i = count-1; i > -1; --i) {
        printf("%d", v[i]);
    }
    free(v);
    return 0;
}
