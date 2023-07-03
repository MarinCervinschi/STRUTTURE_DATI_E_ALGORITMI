#include "cc.h"
#include "list.h"
#include "elemtype.h"
#include <stdlib.h>

int ComponentiConnesse(const Item *i, const ElemType* v, size_t v_size){
    if(!i || !v || v_size == 0){
        return 0;
    }
    
    int componenti = 0;
    int consecutivi = 0;
    
    while (i) {
        
        int presente = 0;
        for (size_t j = 0; j != v_size; ++j) {
            if(i->value == v[j]){
                presente = 1;
                break;
            }
        }
        
        if(presente){
            ++consecutivi;
        }else{
            if(consecutivi > 0){
                ++componenti;
            }
            consecutivi = 0;
        }
        
        i = i->next;
    }
    if (consecutivi > 0) {
            componenti++;
        }
    
    return componenti;
}
