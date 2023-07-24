#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
Item* BucketSort(Item *l){
    if(!l || !l->next){
        return l;
    }
    
    ElemType size = 0, min = 0, max = 0;
    GetMinMaxSize(l, &min, &max, &size);
    
    Item **v = malloc(size * sizeof(Item));
    for (int i = 0; i < size; i++) {
        v[i] = NULL;
    }
    
    for (Item *tmp = l; tmp; tmp = tmp->next) {
        ElemType pos = ( (size-1)*(tmp->value - min) )/ (max - min);
        v[pos] = ListInsertBack(v[pos], &tmp->value);
    }
    
    Item *ret = NULL;
    for (int i = 0; i < size; i++) {
        v[i] = BucketSort(v[i]);
        ret = ConcatList(ret, v[i]);
    }

    Item* tmp = l;
    while (ret) {
        tmp->value = ret->value;
        ret = ret->next;
        tmp = tmp->next;
    }
    ListDelete(ret);
    free(v);
    return l;
}

