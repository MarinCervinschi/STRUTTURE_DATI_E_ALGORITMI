#include "elemtype.h"
#include "list.h"
#include <stdbool.h>


Item *Diff(const Item * i1, const Item *i2) {
    Item *list_ret = ListCreateEmpty();

    for(const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
        bool k = true;
        for (const Item *tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
            if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
                k = false;
                break;
            }
        }
        if(k){
            list_ret = ListInsertBack(list_ret, ListGetHeadValue(tmp1));
        }
    }

    return list_ret;
}
