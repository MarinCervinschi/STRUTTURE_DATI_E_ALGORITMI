#include <stdio.h>
#include <stdlib.h>
void ElemSwap(int *e1, int *e2){
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}
void StoogeRec(int *vector, int start, int end){
    if(vector[start] > vector[end]){
        ElemSwap(&vector[end], &vector[start]);
    }
    
    if(end - start + 1 > 2){
        int thirds = (end - start + 1) / 3;

        // Ordina i primi 2/3 del vettore
        StoogeRec(vector, start, end - thirds);

        // Ordina gli ultimi 2/3 del vettore
        StoogeRec(vector, start + thirds, end);

        // Ordina nuovamente i primi 2/3 del vettore
        StoogeRec(vector, start, end - thirds);
    }
    
}
void Stooge(int *vector, size_t vector_size){
    if(vector_size <= 1){
        return;
    }
    StoogeRec(vector, 0, (int)vector_size-1);
    
    return;
}
