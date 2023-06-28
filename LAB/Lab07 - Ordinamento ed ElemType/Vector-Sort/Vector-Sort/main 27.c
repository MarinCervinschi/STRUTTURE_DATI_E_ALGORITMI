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
    
    
    VectorSort(&ret);
    
    for (int i = 0; i != 4; ++i) {
        printf("%d ", ret.data[i]);
    }
    
    free(ret.data);
    return 0;
}
