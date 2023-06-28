#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
static void CacciatorePredaRec(const char *v, size_t v_size, int u, int *s, int i, bool *k){
    if(i == (int)v_size){
            return;
        }
        
        if(v[i] == 'c' || v[i] == 'C'){
            CacciatorePredaRec(v, v_size, u, s, i+1,k);
            if(!k[i]){
                s[i] = -1;
            }
            return;
        }
        
        if(i+u < (int)v_size && ((v[i] == 'p' || v[i] == 'P') && (v[i+u] == 'c' || v[i+u] == 'C') && !k[i+u] )){
            s[i+u] = i;
            s[i] = -2;
            k[i+u] = true;
            CacciatorePredaRec(v, v_size, u, s, i+1,k);
            
        }else if( i - u >= 0 && ((v[i] == 'p' || v[i] == 'P') && (v[i-u] == 'c' || v[i-u] == 'C') && !k[i-u])){
            s[i-u] = i;
            s[i] = -2;
            k[i-u] = true;
            CacciatorePredaRec(v, v_size, u, s, i+1,k);
        }else{
            s[i] = -1;
            CacciatorePredaRec(v, v_size, u, s, i+1,k);
        }
        
}
int *CacciatorePreda(const char *v, size_t v_size, int u){
    int *s = calloc(v_size, sizeof(int));
    
    bool *k = calloc(v_size, sizeof(bool));
    CacciatorePredaRec(v, v_size, u, s, 0, k);
    free(k);
    return s;
}
