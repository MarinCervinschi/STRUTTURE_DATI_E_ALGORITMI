#include "list.h"
#include "elemtype.h"
#include <stdbool.h>

Item *IntersectNoRep(const Item * i1, const Item *i2) {
    Item *list_ret = ListCreateEmpty();
    
    for(const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
        
        bool h = true;
        for (const Item *k = list_ret; !ListIsEmpty(k); k = ListGetTail(k)) {
            if(ElemCompare(ListGetHeadValue(k), ListGetHeadValue(tmp1)) == 0){
                h = false;
                break;
            }
        }
        if(h){
            for (const Item *tmp2 = i2; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
                if (ElemCompare(ListGetHeadValue(tmp1), ListGetHeadValue(tmp2)) == 0) {
                    list_ret = ListInsertBack(list_ret, ListGetHeadValue(tmp1));
                    break;
                }
            }
        }
    }

    return list_ret;
}

Item *DiffNoRep(const Item * i1, const Item *i2) {
    Item *list_ret = ListCreateEmpty();

    for(const Item *tmp1 = i1; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
        bool k = true, h = true;
        for (const Item *k = list_ret; !ListIsEmpty(k); k = ListGetTail(k)) {
            if(ElemCompare(ListGetHeadValue(k), ListGetHeadValue(tmp1)) == 0){
                h = false;
                break;
            }
        }
        if(h){
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
    }
    return list_ret;
}

