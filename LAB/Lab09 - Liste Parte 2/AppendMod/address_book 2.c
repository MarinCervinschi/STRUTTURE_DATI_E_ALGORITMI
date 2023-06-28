#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
Item *AppendMod(Item *i1, Item *i2){
    if(ListIsEmpty(i1)){
        return i2;
    }
    if(ListIsEmpty(i2)){
        return i1;
    }
    Item *tmp = i2, *tmp1 = i1;
    while (!ListIsEmpty(tmp1)) {
        if(tmp1->next == NULL){
            break;
        }
        tmp1 = tmp1->next;
    }
    while (!ListIsEmpty(tmp)) {
        if(tmp->next == NULL){
            tmp1->next = i2;
            return i1;
        }
        tmp = tmp->next;
    }
    return EXIT_SUCCESS;
}
