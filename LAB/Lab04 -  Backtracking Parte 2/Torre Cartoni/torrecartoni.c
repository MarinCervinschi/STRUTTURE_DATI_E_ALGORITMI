#include "torrecartoni.h"
#include <stdlib.h>
#include <stdbool.h>

void Stampa(unsigned altezza_max, size_t *vbest, size_t cnt){
    for (size_t j = 0; j != cnt; ++j) {
        if(j +1  == cnt){
            printf("%zu\n", vbest[j]);
            printf("Altezza: %u cm\n\n", altezza_max);
            return;
        }
        printf("%zu\n", vbest[j]);
    }
}
void TorreCartoniRec(const Cartone *c, size_t n, size_t i, size_t *vcurr, size_t *vbest, size_t cnt, unsigned altezza, unsigned *altezza_max){
    
    if( i == cnt){
        bool salta = true;
        //verifico che non ci siano due elementi uguali nella mia torre
        for (size_t j = 0; j != cnt; ++j) {
            for (size_t k = 0; k != cnt; ++k) {
              
                if(vcurr[j] == vcurr[k] && k == j){
                    continue;
                }
                if(vcurr[j] == vcurr[k]){
                    salta = false;
                    break;
                }
            }
            if (!salta) {
                break;
            }
        }
                
        if(salta){
            //controllo se la torre corrente rispecchia il numero di soluzioni
            size_t m = 0;
            for (size_t j = 0; j != cnt; ++j) {
                if(j+1 == cnt){
                    ++m;
                    continue;
                }
                if(c[vcurr[j]].p >= c[vcurr[j+1]].l){
                    continue;
                }
                ++m;
            }
            if(m != cnt){
                return;
            }
            bool verifica = true;
            //verifico che il peso del cartone sia giusto per metterlo in pila
            for (size_t j = 0; j != cnt; ++j) {
                for (size_t k = j; k != cnt; ++k) {
                    if(k==j){
                        continue;
                    }
                    if (j + 1 == cnt) {
                        continue;
                    }
                    if(c[vcurr[j]].p >= c[vcurr[k]].l){
                        
                        verifica = false;
                        break;
                    }
                }
                if(!verifica){
                    break;
                }
            }
            //calcolo l'altezza e inserisco la torre migliore nel vettore vbest
            if(verifica){
                for (size_t j = 0; j != cnt; ++j) {
                    altezza += c[vcurr[j]].a;
                }
                if(altezza > *altezza_max){
                    for (size_t j = 0; j != cnt; ++j) {
                        vbest[j] = vcurr[j];
                    }
                    *altezza_max = altezza;
                }
            }
        }
       return;
   }
    //chiamo la funzione ricorsivamente
    for (size_t j = 0; j != n; ++j) {
        vcurr[i] = j;
        TorreCartoniRec(c, n, i+1, vcurr, vbest, cnt ,0 ,altezza_max);
        vcurr[i] = 0;
    }
}

void TorreCartoni(const Cartone *c, size_t n){
    size_t *vcurr = calloc(n, sizeof(size_t));
    size_t *vbest = calloc(n, sizeof(size_t));
    size_t cnt = 0;
    unsigned altezza_max = 0;
    //utilizzo un ciclo per scoprire la dimensione della mia soluzione
    for (size_t j = 0; j != n; j++) {
        size_t k = 0;
        for (size_t i = 0; i != n; ++i) {
            if( c[j].p >= c[i].l && c[i].p != c[j].p ){
                continue;
            }
            ++k;
        }
        if(k> cnt){
            cnt = k;
        }
    }
    
    TorreCartoniRec(c, n, 0, vcurr, vbest, cnt, 0, &altezza_max);
    Stampa(altezza_max, vbest, cnt);
    
    free(vcurr);
    free(vbest);
    return;
}
