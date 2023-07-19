#include <stdio.h>
#include <stdlib.h>
void StepsRec(int n, int index, int sum, int *v_curr, int *n_sol){
    if(sum > n){
        return;
    }
    if(sum == n){
        ++(*n_sol);
        printf("[");
        for (int i = 0; i < n; ++i) {
            if(v_curr[i]){
                if(i + 1 == n && v_curr[i]){
                    printf("%d", v_curr[i]);
                    continue;
                }
                !v_curr[i+1] ? printf("%d", v_curr[i]) : printf("%d, ", v_curr[i]);
            }
        }
        printf("], ");
        return;
    }
    
    v_curr[index] = 1;
    StepsRec(n, index + 1, sum + v_curr[index], v_curr, n_sol);
    v_curr[index] = 2;
    StepsRec(n, index + 1, sum + v_curr[index], v_curr, n_sol);
    v_curr[index] = 3;
    StepsRec(n, index + 1, sum + v_curr[index], v_curr, n_sol);
    v_curr[index] = 0;
}
int Steps(int n){
    if (n == 0) {
        return 0;
    }
    int *v_curr = calloc(n, sizeof(int));
    
    int n_sol = 0;
    StepsRec(n, 0, 0, v_curr, &n_sol);
    free(v_curr);
    return n_sol;
}
