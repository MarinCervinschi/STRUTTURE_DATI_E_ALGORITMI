#include <stdio.h>
#include "elemtype.h"
#include "vettore.h"
#include <stdlib.h>
int main(void) {
   
    Vector ret = {
        .capacity = 5,
        .size = 4,
        .data = calloc(4, sizeof(ElemType))
    };
    
    ret.data[0] = 2;
    ret.data[1] = 9;
    ret.data[2] = 3;
    ret.data[3] = 4;
    
    
    int k = 0;
    ElemType n = 4;
    k = VectorFind(&ret, &n);
    if(k == -1){
        printf("Il numero %d non è presente nel vettore\n", n);
        return 0;
    }
    printf("Il numero %d è alla posizione : %d\n" , n,k);
    
    
    
    free(ret.data);
    return 0;
}
