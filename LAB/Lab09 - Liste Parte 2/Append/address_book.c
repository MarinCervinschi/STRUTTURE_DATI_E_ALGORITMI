#include "elemtype.h"
#include "list.h"
Item *Append(const Item *i1, const Item *i2){
    Item *list_ret = ListCreateEmpty();
    
    for (const Item *tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        list_ret = ListInsertBack(list_ret, ListGetHeadValue(tmp));
    }
    for (const Item *tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        list_ret = ListInsertBack(list_ret, ListGetHeadValue(tmp));
    }
   
    return list_ret;
}
