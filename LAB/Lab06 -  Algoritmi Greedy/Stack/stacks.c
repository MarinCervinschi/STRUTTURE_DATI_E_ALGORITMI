#include "stacks.h"
#include <stdbool.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b){
    const Somma *pa = a;
    const Somma *pb = b;
    unsigned a_value = pa->somma;
    unsigned b_value = pb->somma;
    
    return (a_value < b_value) - (a_value > b_value);
}

unsigned MaxSumNStack(Stack *stacks, size_t n){
    
    Somma *s = calloc(n, sizeof(Somma));
    for (size_t i = 0 ; i != n; ++i) {
        s[i].elements = calloc(stacks[i].m, sizeof(unsigned));
    }
    
    for (size_t i = 0; i != n; ++i) {
        for (size_t k = 0; k != stacks[i].m; ++k) {
            s[i].elements[k] = stacks[i].elements[k];
        }
        s[i].m = stacks[i].m;
    }
    
    while (1) {
        //calcola le somme
        for (size_t i = 0; i != n; ++i) {
            s[i].somma = 0;
            for (size_t k = 0; k != s[i].m; ++k) {
                s[i].somma += s[i].elements[k];
            }
        }
        //ordina
        qsort(s, n, sizeof(Somma), cmpfunc);

        //verifica il risultato
        bool try = true;
        for (size_t h = 0; h != n; ++h) {
            for (size_t j = 0; j != n; ++j) {
                if (h == j) {
                    continue;
                }
                if(s[h].somma != s[j].somma){
                    try = false;
                    break;
                }
                //ritorna
                if(j+1 == n){
                    unsigned ret = s[0].somma;
                    for (size_t i = 0 ; i != n; ++i) {
                        free(s[i].elements);
                    }
                    free(s);
                    return ret;
                }
            }
            if(!try){
                break;
            }
        }
        //togli un numero dalla cima
        s[0].elements[s[0].m-1] = 0;
        --s[0].m;
    }
}
