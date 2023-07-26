#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int AreaCurr(int *v_curr, int size){
    int count = 0;
    for (int i = 0; i<size; ++i) {
        count += v_curr[i];
    }
    return count;
}
static void SolarCutRec(int A, size_t *solar_size, int *v_best, int *v_curr, int count){
    int area = AreaCurr(v_curr, count);
    if(area > A){
        return;
    }
    if(area == A){
        if(count < *solar_size){
            for (int i = 0; i < count; ++i) {
                v_best[i] = v_curr[i];
            }
            *solar_size = count;
        }
        
        return;
    }
    for (int i = 1; i < A; ++i) {
        v_curr[count] = i * i;
        SolarCutRec(A, solar_size, v_best, v_curr, count+1);
        v_curr[count] = 0;
    }
    
}
int* SolarCut(int A, size_t *sol_size){
    int *v_best = calloc(A, sizeof(int));
    int *v_curr = calloc(A, sizeof(int));
    *sol_size = INT_MAX;
    SolarCutRec(A, sol_size, v_best, v_curr, 0);
    
    v_best = realloc(v_best, *sol_size * sizeof(int));
    
    free(v_curr);
    return v_best;
}
