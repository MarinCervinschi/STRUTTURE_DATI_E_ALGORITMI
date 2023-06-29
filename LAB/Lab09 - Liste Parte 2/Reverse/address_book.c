#include "elemtype.h"
#include "list.h"
Item *Reverse(Item *i){
    Item *list_ret = ListCreateEmpty();
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        list_ret = ListInsertHead(ListGetHeadValue(tmp), list_ret);
    }
    return list_ret;
}
