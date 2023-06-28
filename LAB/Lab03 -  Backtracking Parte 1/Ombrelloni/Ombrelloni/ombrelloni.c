#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
void OmbrelloniRec(int k, int n, int i, bool *vcurr, int cnt, int *nsol){
    
    if(cnt == k){
        int salta = true;
        for (int j = 0; j < n - 1; ++j) {
            if (vcurr[j]) {
                if(vcurr[j+1]){
                    salta = false;
                    break;
                }
            }
        }
        if(salta){
            (*nsol)++;
            printf("    %i) ", *nsol);
            for (int j = 0; j < n; ++j) {
                printf("%i ", vcurr[j]);
            }
            printf("\n");
            return;
        } 
    }
    
    if( i == n){
        return;
    }
    
    vcurr[i] = 0;
    OmbrelloniRec(k, n, i+1, vcurr, cnt, nsol);
    
    vcurr[i] = 1;
    OmbrelloniRec(k, n, i+1, vcurr, cnt + 1, nsol);
    vcurr[i] = 0;
}
int Ombrelloni(int k, int n){
    if(k < 0 || n < 0){
        return 0;
    }
    bool *vcurr = calloc(n, sizeof(bool));
    int nsol = 0;
    
    OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
    if(nsol == 0){
        free(vcurr);
        return 0;
    }
    free(vcurr);
    return nsol;
}
int main(void) {

    int nsol = 0;
    nsol = Ombrelloni(2, 4);

    return 0;
}
