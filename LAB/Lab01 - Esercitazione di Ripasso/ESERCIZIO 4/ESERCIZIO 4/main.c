#include <stdio.h>
#include "vettore.h"
#include <stdlib.h>
int main(void) {
    struct vettore *x = calloc(1, sizeof(struct vettore));
    x->size = 3;
    x->data = calloc(3, sizeof(int));
    
    x->data[0] = 1;
    x->data[1] = 2;
    x->data[2] = 3;
    
    Push(x, 4);
    Pop(x);
    
    free(x->data);
    free(x);
    return 0;
}
