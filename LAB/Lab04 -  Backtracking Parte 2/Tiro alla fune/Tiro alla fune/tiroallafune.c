#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void Stampa(int n, int *vbest, int *Insieme){
    printf("{ ");
    int j = 0;
    for (; j != n/2; ++j) {
        if(j+1== n/2){
            printf("%i", Insieme[vbest[j]]);
            continue;
        }
        printf("%i, ", Insieme[vbest[j]]);
    }
    printf(" }, { ");
    for (int k = 0; k != n-(n/2); ++k, ++j) {
        if(k+1== n-(n/2)){
            printf("%i", Insieme[vbest[j]]);
            continue;
        }
        printf("%i, ", Insieme[vbest[j]]);
    }
    printf(" }\n");
    return;
}

bool IsIn( int n,int *vcurr){
    for (int j = 0; j != n/2; ++j) {
        for (int k = 0; k != n/2; ++k) {
            if(k == j){
                continue;
            }
            if(vcurr[j] == vcurr[k]){
                return false;
            }
        }
    }
    return true;
}

void Dividi(int n, int i, int differenza, int *differenza_min, int somma, int somma2, int *somma_max, int *Insieme, int *vcurr, int *vbest){
    
   

    if(i == n){
        
        bool salta = IsIn(n, vcurr);
        if(salta){
            int j = 0;
            for (; j != n/2; ++j) {
                somma += Insieme[vcurr[j]];
            }
            for (int k = 0; k != n-(n/2); ++k, ++j) {
                somma2 += Insieme[vcurr[j]];
            }
            differenza = abs(somma - somma2);
            
            if(differenza < *differenza_min ){
                
                j = 0;
                for (; j != n/2; ++j) {
                    vbest[j] = vcurr[j];
                }
                for (int k = 0; k != n-(n/2); ++k, ++j) {
                    vbest[j] = vcurr[j];
                }
                *somma_max = somma;
                *differenza_min = differenza;
            }
        }
        
        return;
    }
    
    
    for (int j = 0; j != n; ++j) {
        vcurr[i] = j;
        Dividi(n, i+1, 0, differenza_min, 0, 0, somma_max, Insieme, vcurr, vbest);
        vcurr[i] = 0;
    }
}


int main(int argc, const char * argv[]) {
    
    
    
    int *Insieme = calloc(argc, sizeof(int));
    for (int i = 1; i != argc; ++i) {
        Insieme[i-1] = atoi(argv[i]);
    }
    int *vcurr = calloc(argc - 1, sizeof(int));
    int *vbest = calloc(argc - 1, sizeof(int));
    int somma_max = 0, differenza_min = 1000;
    
    Dividi(argc-1, 0, 0, &differenza_min, 0, 0, &somma_max, Insieme, vcurr, vbest);
    Stampa(argc -1, vbest, Insieme);
    
    free(vcurr);
    free(vbest);
    free(Insieme);
    return 0;
}
