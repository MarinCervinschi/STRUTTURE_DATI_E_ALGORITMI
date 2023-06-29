#include "elemtype.h"
#include "list.h"
#include <string.h>
Item *Filtra(Item *i, const char *city){
    Item *list_ret = ListCreateEmpty();
    const ElemType *k;
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        k = ListGetHeadValue(tmp);
        if(strcmp(k->city, city) == 0){
            list_ret = ListInsertBack(list_ret, k);
        }
    }
    return list_ret;
}
