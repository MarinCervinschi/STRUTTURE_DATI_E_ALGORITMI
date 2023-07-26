#include <stdio.h>
#include <stdlib.h>
int SoluzioneOttima(int A){
    if (A == 1) {
        return 1;
    }
    int area = 0;
    for (int i = 1; i < A; ++i) {
        if(i * i <= A){
            area = i * i;
        }
    }
    return area;
}
int* SolarCut(int A, size_t *sol_size){
    int *v_best = calloc(A, sizeof(int));
    *sol_size = 0;
    int index = 0;
    while (A != 0) {
        v_best[index] = SoluzioneOttima(A);
        A -= v_best[index];
        ++index;
    }
    *sol_size = index;
    v_best = realloc(v_best, *sol_size * sizeof(int));
    
    return v_best;
}
