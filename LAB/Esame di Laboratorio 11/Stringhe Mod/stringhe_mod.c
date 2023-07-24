#include <stdio.h>
#include <stdlib.h>
static void BacktrackStrModRec(int n, int k, char *v_curr, int index){
    if(index == k){
        printf("{%s}, ", v_curr);
        return;
    }
    for (int i = 0; i < n; ++i) {
        v_curr[index] = 'a' + i;
        BacktrackStrModRec(n, k, v_curr, index + 1);
        v_curr[index] = 0;
    }
}
void BacktrackStrMod(int n, int k){
    if(n <= 0 || n > 26 || k <= 0){
        return;
    }
    char *v_curr = calloc(k+1, sizeof(char));
    
    BacktrackStrModRec(n, k, v_curr, 0);
    
    free(v_curr);
}
