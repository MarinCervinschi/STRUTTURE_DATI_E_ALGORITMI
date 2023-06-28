#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
#include "list.h"
#include <string.h>
const ElemType *Find(const Item *i, const char *name){
    const ElemType *k;
    
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        k = ListGetHeadValue(tmp);
        if(strcmp(name, k->name) == 0){
            return k;
        }
    }
    
    return NULL;
}
