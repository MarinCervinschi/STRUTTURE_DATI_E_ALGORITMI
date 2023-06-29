#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void BacktrackSommaRec(int n, int i, bool vcurr[], int w[], int obiettivo, int sommacurr, int rimanenza, int *nsol){
    
    if (sommacurr == obiettivo) { // stampa soluzione
        (*nsol)++;
        printf("%d) ", *nsol);
        for(int j=0;j<i;j++){
            printf("%d ", vcurr[j]);
        }
//        for(int j=i;j<n;j++){
//            printf("“0 ");
//        }
        printf("\n");
        return;
    }
    
    if (i == n){
        return;
    }
    rimanenza -= w[i];
    
    if ((sommacurr + rimanenza >= obiettivo) && (i == n-1 || (i < n-1 && sommacurr + w[i+1] <= obiettivo))){
        vcurr[i] = 0;
        BacktrackSommaRec(n, i+1, vcurr, w, obiettivo, sommacurr, rimanenza, nsol);
    }
    if (sommacurr + w[i] <= obiettivo) {
        vcurr[i] = 1;
        BacktrackSommaRec(n, i+1, vcurr, w, obiettivo, sommacurr + w[i], rimanenza, nsol);
    }
}
                       
int BacktrackSomma(int n, int obbiettivo, int w[]){
    bool *vcurr = malloc(n* sizeof(bool));
    int nsol = 0, rimanenza = 0;
    for (int j = 0; j != n; ++j) {
        rimanenza += w[j];
    }
    BacktrackSommaRec(n, 0, vcurr, w, obbiettivo, 0, rimanenza, &nsol);
    
    free(vcurr);
    return nsol;
}
                       
int main(void) {
    
    int w[] = {7, 11, 13, 24};
    BacktrackSomma(4, 31, w);
    
    return 0;
}
