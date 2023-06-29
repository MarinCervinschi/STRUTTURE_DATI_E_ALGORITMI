#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool verifica(size_t n, int *vccur){
    bool try = true;
    
    for (size_t i = 0; i != n-2; ++i) {
        if( ( vccur[i] < vccur[i+1] && vccur[i+1] > vccur[i+2] ) ||
                                                                    (vccur[i] > vccur[i+1] && vccur[i+1] < vccur[i+2])){
            continue;
        }
        try = false;
        break;
    }
    return try;
}

void Stampa(size_t n, int *vccur){
    for (size_t i = 0; i != n; ++i) {
        if(i == 0){
            printf("(%d, ", vccur[i]);
            continue;
        }
        if(i+1 == n){
            printf("%d), ", vccur[i]);
            continue;
        }
        printf("%d, ", vccur[i]);
        
    }
}
void GolaCrestaRec(size_t n ,int i,int *vccur){
    if(i == (int)n){
        if(verifica(n, vccur)){
            Stampa(n, vccur);
        }
        return;
    }
    
    vccur[i] = 0;
    GolaCrestaRec(n, i+1, vccur);
    vccur[i] = 1;
    GolaCrestaRec(n, i+1, vccur);
    vccur[i] = 2;
    GolaCrestaRec(n, i+1, vccur);
    
   
}
void GolaCresta(size_t n){
    if(n < 3){
        return;
    }
    
    int *vccur = calloc(n, sizeof(int));
    GolaCrestaRec(n, 0, vccur);
    
    free(vccur);
}
