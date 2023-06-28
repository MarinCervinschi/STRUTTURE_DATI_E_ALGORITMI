#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
void stampaSoluzione(size_t pacchi_size, bool *vBest){
    for (size_t j = 0; j != pacchi_size; ++j) {
        printf("%i ", vBest[j]);
    }
}
void BabboNataleRec( int n, const int *pacchi, size_t pacchi_size, int p, unsigned int i, bool *vcurr, bool *vBest, int *max, int sumMax, int cnt, int sum){
    if (cnt == n) {
        for (size_t j = 0; j < pacchi_size; ++j) {
            if(vcurr[j]){
                sum += pacchi[j];
                (sumMax)++;
            }
        }
        if(sum < p){
            if(sumMax > *max){
                for (size_t j = 0; j != pacchi_size; ++j) {
                    vBest[j] = vcurr[j];
                }
                *max = sumMax;
            }
        }
        return;
    }
    if (i == pacchi_size){
        return;
    }
    
    vcurr[i] = 0;
    BabboNataleRec(n,pacchi, pacchi_size, p, i+1, vcurr, vBest, max, sumMax, cnt, sum);

    vcurr[i] = 1;
    BabboNataleRec(n,pacchi, pacchi_size, p, i+1, vcurr, vBest, max, sumMax, cnt+1, sum);
}
void BabboNatale(const int *pacchi, size_t pacchi_size, int p){
    bool *vcurr = malloc(sizeof(bool) * pacchi_size);
    bool *vBest = calloc(pacchi_size, sizeof(bool));
    int max = 0, sumMax = 0, n=0;
    
    for (size_t j = 0; j != pacchi_size; ++j) {
        sumMax += pacchi[j];
        if(sumMax < p){
            ++n;
        }else{
            sumMax -= pacchi[j];
        }
    }
    BabboNataleRec(n,pacchi, pacchi_size, p, 0, vcurr, vBest, &max, 0, 0, 0);
    stampaSoluzione(pacchi_size, vBest);
    free(vcurr);
    free(vBest);
}

int main(void){

    const int pacchi[] ={10, 15, 13, 100, 23, 49, 30, 5 };
    BabboNatale(pacchi, 8, 100);
    return EXIT_SUCCESS;
}
