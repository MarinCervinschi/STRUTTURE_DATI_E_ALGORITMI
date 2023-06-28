#include <stdio.h>
#include "elemtype.h"
#include "doublelist.h"
#include <stdlib.h>
Item *ConcatenaN(Item **v, size_t v_size){
    if (v_size == 0) {
        return NULL;
    }
    
    for (size_t i = 0; i != v_size - 1; ++i) {
        if (DListIsEmpty(v[i])) {
            v[i] = v[i+1];
            continue;
        }
        Item *tmp1 = v[i];
        while (!DListIsEmpty(tmp1)) {
            if(tmp1->next == NULL){
                if(v[i+1] == NULL){
                    if(i+2 >= v_size){
                        break;
                    }
                    tmp1->next = v[i+2];
                    tmp1->next->prev = tmp1;
                    break;
                }
                tmp1->next = v[i+1];
                tmp1->next->prev = tmp1;
                break;
            }
            tmp1 = tmp1->next;
        }

    }
    
    return v[0];
}
