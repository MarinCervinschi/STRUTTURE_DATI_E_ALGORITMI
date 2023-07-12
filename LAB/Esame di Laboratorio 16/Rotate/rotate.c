#include "list.h"
#include <stdlib.h>
int ListLength(Item *i){
    if(!i){
        return 0;
    }
    return ListLength(i->next) + 1;
}
Item *Rotate(Item *i, int n){
    if(!i){
        return NULL;
    }
    Item *head = i;
    int dim = ListLength(i) -1;
    
    for (int i = 0; i < n; ++i) {
        Item *curr = head;
        Item *prev = NULL;
        
        for (int j = 0; j < dim && curr->next; ++j) {
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
            
            prev = foll;;
        }
    }

    return head;
}
