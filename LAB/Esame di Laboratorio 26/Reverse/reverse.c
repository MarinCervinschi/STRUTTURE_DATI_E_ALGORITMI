#include "reverse.h"

int ListLength(Item *list){
    if(!list){
        return 0;
    }
    return ListLength(list->next)+1;
}
Item *Revert(Item *list){
    Item *last = list;
    
    Item *curr = list->next;
    Item *foll = curr->next;
    last->next = NULL;
    while (foll) {
        curr->next = last;
        last = curr;
        curr = foll;
        foll = foll->next;
    }
    curr->next = last;
    
    return curr;
}
Item* Reverse(Item *list, int left){
    if(!list){
        return NULL;
    }
    
    int dim = ListLength(list)-1;
    if(left >= dim){
        return list;
    }
    if(left <= 0){
        return Revert(list);
    }
    
    Item *head = list;
    for (int i = 0; i < left-1; ++i) {
        list = list->next;
    }
    Item *to_reverse = list->next;
    to_reverse = Revert(to_reverse);
    list->next = to_reverse;
    return head;
}

