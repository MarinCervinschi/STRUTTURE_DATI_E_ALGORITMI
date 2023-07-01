#include "next_greater.h"
#include <limits.h>
#include <stdlib.h>
#include "list.h"
#include "elemtype.h"
int ListLenght(const Item *list){
    if(!list){
        return 0;
    }
    return ListLenght(list->next) + 1;
}
ElemType TrovaNextValue(const Item *list, ElemType value){
    for (const Item *tmp = list; tmp; tmp = tmp->next) {
        if(tmp->value > value){
            return tmp->value;
        }
    }
    return INT_MIN;
}
ElemType* NextGreater(const Item *list, size_t *answer_size){
    if(!list){
        *answer_size = 0;
        return NULL;
    }
    *answer_size = ListLenght(list);
    ElemType *ret = calloc(*answer_size, sizeof(ElemType));
    
    const Item *tmp = list;
    for (int i = 0; tmp; ++i) {
        ret[i] = TrovaNextValue(tmp->next, tmp->value);
        tmp = tmp->next;
    }
    
    return ret;
}
