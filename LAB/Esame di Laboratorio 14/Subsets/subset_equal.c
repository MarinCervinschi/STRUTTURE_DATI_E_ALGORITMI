#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool IsIn(int n, int *v, int curr){
    for (int i = 1; i < n+1; ++i){
        if(curr == v[i]){
            return true;
        }
    }
    return false;
}
static void SubsetEqualRec(int n, int s, int index, int somma, int *v_curr){
    if(somma == s){
        printf("{");
        for (int i = 1; i < n; ++i) {
            if (v_curr[i] != 0) {
                printf(" %d", v_curr[i]);
            }
        }
        printf(" }, ");
        return;
    }
    if(index == n){
        return;
    }
    
    for (int i = index; i < n+1; ++i) {
        if(!IsIn(n, v_curr, i)){
            v_curr[index] = i;
            SubsetEqualRec(n, s, i + 1, somma + i, v_curr);
            v_curr[index] = 0;
        }
    }
    
}
void SubsetEqual(int n, int s){
    if(n == 1 || s == 0){
        return;
    }
    int *v_curr = calloc(n, sizeof(int));
    SubsetEqualRec(n, s, 1, 0, v_curr);
    
    free(v_curr);
}
