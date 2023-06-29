#include <stdio.h>
#include "elemtype.h"
#include "vettore.h"
#include <stdlib.h>
int main(void) {
   
    Vector *ret, *ret1, *ret2;
    ret = VectorRead("input_int_01.txt");
    ret1 = VectorReadSorted("input_int_01.txt");
    ret2 = VectorReadSorted("input_int_02.txt");
    
    
    printf("File 1: ");
    for (size_t i = 0; i != ret1->size; ++i) {
        printf("%d ", ret1->data[i]);
        if( i +1 == ret1->size){
            printf("\n\n");
        }
    }
    printf("File 2: ");
    for (size_t i = 0; i != ret2->size; ++i) {
        printf("%d ", ret2->data[i]);
        if( i +1 == ret2->size){
            printf("\n");
        }
    }
    
    return 0;
}
