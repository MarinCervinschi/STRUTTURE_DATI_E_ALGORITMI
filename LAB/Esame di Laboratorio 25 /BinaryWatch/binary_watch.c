#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
struct NumOra{
    int num_hh;
    int num_mm;
};
typedef struct NumOra NumOra;
void StampaOra(int num_hh, int num_mm){
    if (num_hh < 10 && num_mm < 10) {
            printf("0%d:0%d, ", num_hh, num_mm);
        } else if (num_hh < 10) {
            printf("0%d:%d, ", num_hh, num_mm);
        } else if (num_mm < 10) {
            printf("%d:0%d, ", num_hh, num_mm);
        } else {
            printf("%d:%d, ", num_hh, num_mm);
        }
}
NumOra *CalcNun(uint8_t *hh, uint8_t *mm, bool *vccur){
    NumOra *ret = calloc(1, sizeof(NumOra));
    
    for (int i = 0; i != 6; ++i) {
        if(!vccur[i]){
            continue;
        }
        ret->num_mm += mm[i];
    }
    for (int i = 6; i != 11; ++i) {
        if(!vccur[i]){
            continue;
        }
        ret->num_hh += hh[i-6];
    }
    return ret;
}
void ValidTimesRec(uint8_t n, uint8_t* hh, uint8_t* mm, bool* vccur, int index, int count){
    if (count == n) {
            NumOra* num = CalcNun(hh, mm, vccur);
            if (num->num_hh <= 23 && num->num_mm <= 59) {
                StampaOra(num->num_hh, num->num_mm);
            }
            free(num);
            return;
        }
    
    for (int i = index; i < 11; ++i) {
            if (!vccur[i]) {
                vccur[i] = true;
                ValidTimesRec(n, hh, mm, vccur, i + 1, count + 1);
                vccur[i] = false;
            }
        }
}
void ValidTimes(uint8_t n){
    if(n > 11){
        return;
    }
    uint8_t hh[] = { 1, 2, 4, 8, 16};
    uint8_t mm[] = { 1, 2, 4, 8, 16, 32};
    
    bool *vccur = calloc(11, sizeof(bool));
    ValidTimesRec(n, hh, mm, vccur, 0, 0);
    free(vccur);
}
