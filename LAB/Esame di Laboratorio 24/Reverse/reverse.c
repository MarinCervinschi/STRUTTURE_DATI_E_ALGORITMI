#include "reverse.h"
#include <stdlib.h>
int ListLength(Item *list){
    if(!list){
        return 0;
    }
    return ListLength(list->next) + 1;
}
Item* Reverse(Item *list, int right){
    if (right <= 1 || ListIsEmpty(list)) {
        return list;
    }
    
    int len = ListLength(list);
    if(right >= len){
        right = len;;
    }

    Item *head = list;
    int done = 0;
    while (!done) {
        done = 1;
        Item *prev = NULL;
        Item *curr = head;
        for (int i = 0; i < right-1 && curr->next; ++i) {
            Item *foll = curr->next;
            Item *follfoll = foll->next;
            
            if(!prev){
                head = foll;
                
                curr->next = follfoll;
                foll->next = curr;
            }else{
                prev->next = foll;
                curr->next = follfoll;
                foll->next = curr;
            }
            prev = foll;
            done = 0;
        }
        --right;
    }
    
    return head;
}
