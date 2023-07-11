#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int BambiniSoddisfatti(const int* bam, size_t bam_size, size_t bis_size, int *vccur){
    int bamb = 0;
    //bambini soddisfatti
    int *sod = calloc(bam_size, sizeof(int));
    for (size_t i = 0; i < bis_size; ++i) {
        int biscotti = vccur[i];
        for (size_t j = 0; j < bam_size; ++j){
            if(!sod[j]){
                if(biscotti >= bam[j]){
                    bamb++;
                    sod[j] = 1;
                }else{
                    while (biscotti < bam[j] && i++ < bis_size) {
                        biscotti += vccur[i];
                    }
                    if(biscotti >= bam[j]){
                        bamb++;
                        sod[j] = 1;
                    }
                }
                break;
            }
        }
    }
    free(sod);
    return bamb;
}
void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int *vccur, int bam_sod, int *bam_sod_max, size_t count){
    if(count == bis_size){
        bam_sod = BambiniSoddisfatti(bam, bam_size, bis_size, vccur);
        if(bam_sod > *bam_sod_max){
            *bam_sod_max = bam_sod;
        }
        return;
    }
    
    vccur[count] = bis[count];
    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, vccur, bam_sod, bam_sod_max, count + 1);
}
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size){
    if(!bam || !bis || bam_size == 0 || bis_size == 0){
        return 0;
    }
    int bam_sod_max = INT_MIN;
    int *vccur = calloc(bis_size, sizeof(int));
    
    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, vccur, 0, &bam_sod_max, 0);
    
    free(vccur);
    return bam_sod_max;
}
