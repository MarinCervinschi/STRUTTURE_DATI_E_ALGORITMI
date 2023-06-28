#include <stdlib.h>
#include <stdio.h>
int halistoneRec(int n, int *num ){
    if(n == 1){
        printf("%d",n);
        return n;
    }
    printf("%d, ", n);
    ++*num;
    if(n%2 == 0){
        return halistoneRec(n/2, num);
    }else{
        return halistoneRec(n*3+1, num);
    }
}
int halistone(int n){
    if(n <= 0){
        return 0;
    }
    int num = 1;
    halistoneRec(n, &num);
    return num;
}
int main(int argc, const char * argv[]) {
    if (argc != 2) {
        return -1;
    }
    int n = atoi(argv[1]);
    
    return halistone(n);
}
