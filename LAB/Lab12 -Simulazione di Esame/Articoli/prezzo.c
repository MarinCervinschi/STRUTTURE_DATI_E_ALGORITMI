#include "prezzo.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void TrovaArticoliRec(const struct Articolo *a, size_t a_size, int sum, size_t i, int act_sum, bool *k){
   
    if( act_sum == sum){
        for (size_t j = 0; j != a_size; ++j) {
            if(k[j]){
                printf("%s, ", a[j].nome);
            }
        }
        printf("\n");
        return;
    }
    if(i >= a_size || act_sum > sum){
        return;
    }
    
    k[i] = 1;
    TrovaArticoliRec(a, a_size, sum, i + 1, act_sum + a[i].prezzo, k);
    k[i] = 0;
    TrovaArticoliRec(a, a_size, sum, i +1, act_sum, k);
    
}
void TrovaArticoli(const struct Articolo *a, size_t a_size, int sum){
    bool *k = calloc(a_size, sizeof(bool));
    TrovaArticoliRec(a, a_size, sum, 0, 0, k);
    free(k);
}
