#include "list.h"
#include <stdlib.h>
int ListLength(const Item *i){
    if(!i){
        return 0;
    }
    return ListLength(i->next) + 1;
}
const Item* CommonTail(const Item* i1, const Item* i2){
    if (!i1 || !i2) {
        return NULL;
    }
    int dim_i1 = ListLength(i1);
    int dim_i2 = ListLength(i2);
    
    if(dim_i1 > dim_i2){
        for (int j = 0; j < dim_i1-dim_i2; ++j) {
            i1 = i1->next;
        }
    }else if (dim_i1 < dim_i2){
        for (int j = 0; j < dim_i2-dim_i1; ++j) {
            i2 = i2->next;
        }
    }
    for (int j = 0; j < dim_i1-1; ++j) {
        if(i1->next == i2->next){
            return i1;
        }
        i1 = i1->next;
        i2 = i2->next;
    }
    return NULL;
}
