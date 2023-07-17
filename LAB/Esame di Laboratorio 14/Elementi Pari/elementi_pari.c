#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
Item* ElementiPari(const Item* i){
    if(!i){
        return NULL;
    }
    Item *ret = NULL;
    int index = 0;
    for (const Item *tmp = i; tmp; tmp = tmp->next) {
        if(index++ % 2 == 0){
            ret = ListInsertBack(ret, &tmp->value);
        }
    }
    return ret;
}
