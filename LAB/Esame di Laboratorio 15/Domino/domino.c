#include "domino.h"
bool ControllaPosizione(const Tessera *t, Placing *v_curr, size_t index){
    if(v_curr[index-1].flipped){
        return t[v_curr[index-1].indice].val1 == t[index].val1 ? true : false;
    }
    return t[v_curr[index-1].indice].val2 == t[index].val1 ? true : false;
}
void DominoRec(const Tessera *t, size_t t_size, size_t *ret_size, Placing *v_best, Placing *v_curr, size_t index){
    if(index == t_size){
        return;
    }
    
    size_t size = sizeof(*v_curr) / sizeof(Placing);
    
    if(size > *ret_size){
        *ret_size = size;
        for (size_t i = 0; i < size; ++i) {
            v_best[i] = v_curr[i];
        }
    }
    
    
    
    
    for (size_t i = 0; i < t_size; ++i) {
        
        if(index > 0 && ControllaPosizione(t, v_curr, index+1)){
            v_curr[index].indice = (uint32_t)i;
            DominoRec(t, t_size, ret_size, v_best, v_curr, index + 1);
            v_curr[index].indice = 0;
            continue;
        }
        v_curr[index].flipped = true;
        if(ControllaPosizione(t, v_curr, index+1)){
            v_curr[index+1].indice = (uint32_t)index+1;
            DominoRec(t, t_size, ret_size, v_best, v_curr, index + 1);
            v_curr[index].indice = 0;
            continue;
        }
        v_curr[index].flipped = false;
    }
}

Placing *Domino(const Tessera *t, size_t t_size, size_t *ret_size){
    if(!t || t_size == 0){
        *ret_size = 0;
        return NULL;
    }
    Placing *v_curr = calloc(t_size, sizeof(Placing));
    Placing *v_best = calloc(t_size, sizeof(Placing));
    *ret_size = 0;
    
    DominoRec(t, t_size, ret_size, v_best, v_curr, 0);
    
    v_best = realloc(v_best, *ret_size * sizeof(Placing));
    
    free(v_curr);
    return v_best;
}
