#include "elemtype.h"
#include "list.h"
#include <string.h>
#include <stdbool.h>
bool Find(const Item *i, const char *name){
    const ElemType *k;
    
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        k = ListGetHeadValue(tmp);
        if(strcmp(name, k->name) == 0){
            return true;
        }
    }
    
    return false;
}

