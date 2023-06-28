#include "list.h"

Item *Intersect(const Item * i1, const Item *i2) {
    Item *inter = ListCreateEmpty();

    for(const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
        for (const Item *tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
            if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
                inter = ListInsertBack(inter, ListGetHeadValue(tmp1));
                break;
            }
        }
    }

    return inter;
}
