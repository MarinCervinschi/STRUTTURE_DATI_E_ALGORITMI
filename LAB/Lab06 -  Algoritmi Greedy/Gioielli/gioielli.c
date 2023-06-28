#include "gioielli.h"
#include <stdio.h>
#include <stdlib.h>

int CompareGioielli(const void *a, const void *b) {
    const Gioiello *pa = a;
    const Gioiello *pb = b;
    float a_value = pa->peso / pa->prezzo;
    float b_value = pb->peso / pb->prezzo;

    return (a_value < b_value) - (a_value > b_value);
}

Gioiello *CompraGioielli(const char *filename, float budget, size_t *ret_size){
    
    FILE *f = fopen(filename, "r");
    if(!f){
        return NULL;
    }
    Gioiello *count = calloc(1, sizeof(Gioiello));
    int num = -1;
    while (1) {
        fscanf(f, "%i", &count->codice);
        fscanf(f, "%f", &count->peso);
        ++num;
        if(fscanf(f, "%f", &count->prezzo)  != 1){
            break;
        }
    }
    rewind(f);
    free(count);
    Gioiello *ret = calloc(num, sizeof(Gioiello));
    Gioiello *ret_best = calloc(num, sizeof(Gioiello));
    
    for (int i = 0; i != num; ++i) {
        fscanf(f, "%i", &ret[i].codice);
        fscanf(f, "%f", &ret[i].peso);
        fscanf(f, "%f", &ret[i].prezzo);
    }
    
    qsort(ret, num, sizeof(Gioiello), CompareGioielli);
    
    float soldi_rimasti = budget;
    int i = 0;
    size_t a_size = 0;
    while (soldi_rimasti > 0 && i < num) {
        if(ret[i].prezzo <= soldi_rimasti){
            ret_best[a_size++] = ret[i];
            soldi_rimasti -= ret[i].prezzo;
        }
        ++i;
    }
    *ret_size = a_size;
    ret_best = realloc(ret_best, a_size *sizeof(Gioiello));
    
    free(ret);
    fclose(f);
    return ret_best;
    
}
