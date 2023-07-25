#ifndef reverse_h
#define reverse_h

#include "list.h"
#include <stdlib.h>
extern Item* Reverse(Item *list, int left);
#endif /* reverse_h */

reverse.c
#include "reverse.h"

int ListLength(Item *list){
    if(!list){
        return 0;
    }
    return ListLength(list->next)+1;
}
Item* Reverse(Item *list, int left){
    if(!list){
        return NULL;
    }
    
    int dim = ListLength(list)-1;
    if(left >= dim){
        return list;
    }
    
    Item *head = list;
    for (int i = 0; i < left; ++i) {
        head = head->next;
        --dim;
    }
    int done = 0;
    
    while (!done) {
        done = 1;
        
        Item *curr = head;
        Item *prev = NULL;
        
        for (int i = 0; i < dim && curr->next; ++i) {
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
        
        --dim;
    }
    if (left <= 0) {
        return head;
    }
    
    Item *j = list;
    while (j->next->next) {
        j = j->next;
    }
    j->next = head;
    return list;
}
