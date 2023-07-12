#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int PosCurr(int n, int a, int b, char *v_curr){
    int ret = 0;
    for (int i = 0; i < n; ++i){
        if(v_curr[i] == 'a'){
            ret += a;
        }else if (v_curr[i] == 'b'){
            ret -= b;
        }
    }
    return ret;
}
bool PosGood(const int *f,size_t f_size, int pos){
    for (size_t j = 0; j < f_size; ++j){
        if(pos == f[j]){
            return false;
        }
    }
    return true;
}
void GuidaLaPulceRec(const int *f, size_t f_size, int a, int b, int n, int h, size_t *ret_size, int index, char *v_best, char *v_curr){
    int pos_curr =PosCurr(n, a, b, v_curr);
    if(pos_curr == h){
        size_t size = 0;
        for (int i = 0; i < n; ++i){
            if(v_curr[i] != 0){
                ++size;
            }
        }
        if(size < *ret_size){
            *ret_size = size;
            for (size_t i = 0; i < size; ++i){
                v_best[i] = v_curr[i];
            }
        }
        return;
    }else if (pos_curr > h) {
        if(index == n){
            return;
        }
        if(PosGood(f, f_size, pos_curr)){
            v_curr[index] = 'b';
            GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, index+1, v_best, v_curr);
            v_curr[index] = 0;
        }else{
            return;
        }
    }
    
    if(index == n){
        return;
    }
    if(v_curr[index] == 0 && PosGood(f, f_size, pos_curr)){
        v_curr[index] = 'a';
        GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, index+1, v_best, v_curr);
    }
}

char *GuidaLaPulce(const int *f, size_t f_size, int a, int b, int n, int h, size_t *ret_size){
    char *v_best = calloc(n, sizeof(char));
    char *v_curr = calloc(n, sizeof(char));
    
    *ret_size = INT_MAX;
    
    GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, 0, v_best, v_curr);
    
    if(*ret_size == INT_MAX){
        *ret_size = 0;
        free(v_best);
        free(v_curr);
        return NULL;
    }
    
    v_best = realloc(v_best, *ret_size+1 * sizeof(char));
    free(v_curr);
    return v_best;
}
