#include "shift.h"
#include "list.h"
#include "elemtype.h"
#include <stdlib.h>

size_t Len(Item *t){
    size_t num =0 ;
    Item *k = t;
    while (k) {
        k = k->next;
        ++num;
    }
    return num-1;
}

Item *ShiftN(Item *list, size_t n){
    if(ListIsEmpty(list) || list->next == NULL){
        return list;
    }
    size_t len = Len(list);
    
    if(n >= len){
        n %= len;
    }
    
    Item *next = NULL;
    Item *current = list;
    Item *prev = NULL;

 
    for (size_t i = 0; i != n; ++i) {
        next = current->next;
        
        current->next = next->next;
        next->next = current;
        if(prev == NULL){
            prev = next;
            list = prev;
        }else{
            Item *tmp1 = list;
            while (tmp1) {
                if(next->next->value == tmp1->next->value){
                    prev = next;
                    tmp1->next = prev;
                    break;
                }
                tmp1 = tmp1->next;
            }
        }
    }
    
    return list;
}

