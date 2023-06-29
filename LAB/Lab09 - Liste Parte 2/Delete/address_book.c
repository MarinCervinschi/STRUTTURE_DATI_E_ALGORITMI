#include <stdlib.h>
#include "elemtype.h"
#include "list.h"
#include <string.h>
Item *Delete(Item *i, const char *name){
    if (ListIsEmpty(i) || !name) {
        return i;
    }
    for (Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        Item *address = ListGetTail(tmp);
        if(ListIsEmpty(address)){
            return i;
        }
        if(strcmp(name, ListGetHeadValue(tmp)->name) == 0){
            free(address);
            return i->next;
        }
        if(strcmp(name, ListGetHeadValue(address)->name) == 0){
            Item *k = ListGetTail(address);
            tmp->next = k;
            free(address);
            break;
        }
        
    }
    return i;
}
