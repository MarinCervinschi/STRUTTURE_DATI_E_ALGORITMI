#include "doublelist.h"
#include <stdlib.h>
Item *Concatena(Item *i1, Item *i2){
    if(!i1){
        return i2;
    }
    if(!i2){
        return i1;
    }
    Item *tmp = i1;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = i2;
    tmp->next->prev = tmp;
    return i1;
}
Item *ConcatenaN(Item **v, size_t v_size){
    if (v_size == 0) {
        return NULL;
    }
    for (size_t i = 1; i < v_size; ++i) {
        v[0] = Concatena(v[0], v[i]);
    }
    return v[0];
}
