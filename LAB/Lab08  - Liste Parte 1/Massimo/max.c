#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
const ElemType *MaxElement(const Item *i){
    if (ListIsEmpty(i)) {
        return NULL;
    }
    const ElemType *max = NULL;
    max = ListGetHeadValue(i);
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        if (ElemCompare(max, ListGetHeadValue(tmp)) < 0) {
            max = ListGetHeadValue(tmp);
        }
    }
    
    return max;
}
