#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool verifica(size_t n, bool *vccur){
    for (size_t i = 0; i != n-1; ++i) {
        if(vccur[i] && !vccur[i+1]){
            return false;
        }
    }
    return true;
}
void OptimalSubarrayRec(const int *v, size_t n, int count, int *somma_max, int somma, bool *vccur){
    if(count == (int)n){
        if(somma > *somma_max && verifica(n, vccur)){
            *somma_max = somma;
        }
        return;
    }
    if(somma > *somma_max && verifica(n, vccur)){
        *somma_max = somma;
    }

    
    vccur[count] = true;
    OptimalSubarrayRec(v, n, count + 1, somma_max, somma+v[count], vccur);
    vccur[count] = false;
    OptimalSubarrayRec(v, n, count + 1, somma_max, somma, vccur);
    
    return ;
}
int OptimalSubarray(const int *v, size_t n){
    if (n == 0) {
        return 0;
    }
    int somma_max = 0;
    
    bool *vccur = calloc(n, sizeof(bool));
    OptimalSubarrayRec(v, n, 0, &somma_max, 0, vccur);
    
    free(vccur);
    return somma_max;
}
