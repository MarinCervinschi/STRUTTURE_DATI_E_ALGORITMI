#include "list.h"
#include "elemtype.h"
#include <stdlib.h>

Item* CreaDaMinori(const Item* i, int v){
    if(!i){
        return NULL;
    }
    Item *ret = NULL;
    
    for (const Item *tmp = i; tmp; tmp = tmp->next) {
        if(tmp->value <= v){
            ret = ListInsertBack(ret, &tmp->value);
        }
    }
    return ret;
}
