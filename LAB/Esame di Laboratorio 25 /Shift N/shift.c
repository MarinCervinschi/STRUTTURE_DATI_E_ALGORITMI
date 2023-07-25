#include "shift.h"
size_t Len(Item *t){
    if(!t){
        return 0;
    }
    return Len(t->next) + 1;
}
Item *ShiftN(Item *list, size_t n){
    if(ListIsEmpty(list) || !list->next){
        return list;
    }
    size_t len = Len(list)-1;
    
    if(n >= len){
        if(n % len == 0){
            n = len;
        }else{
            n %= len;
        }
    }
    
    Item *head = list;
    
    Item *current = head;
    Item *prev = NULL;
    
    for (size_t i = 0; i < n; ++i) {
        Item *foll = current->next;
        Item *follfoll = foll->next;
        
        if(!prev){
            head = foll;
            current->next = follfoll;
            foll->next = current;
        }else{
            prev->next = foll;
            current->next = follfoll;
            foll->next = current;
        }
        prev = foll;
    }
    
    return head;
}

