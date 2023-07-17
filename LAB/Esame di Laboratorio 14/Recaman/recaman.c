#include <stdio.h>
int RecmanRec(int n){
    if(n == 1){
        return 1;
    }
    return RecmanRec(n-1) % n  == 0 ? RecmanRec(n-1)/ n : n * RecmanRec(n-1);
}
int Recaman(int n){
    if( n < 1){
        return -1;
    }
    return n == 1 ? 1 : RecmanRec(n-1);
}
