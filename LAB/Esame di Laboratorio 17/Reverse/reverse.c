#include <stdlib.h>
#include "list.h"
#include "elemtype.h"
int ListLength(Item *t){
    if(!t){
        return 0;
    }
    return ListLength(t->next) +1;
}
Item *Reverse(Item *i){
    if (!i) {
        return NULL;
    }
    int dim = ListLength(i)-1;
    Item *head = i;
    for (int h = 0; h < dim; ++h){
        Item *prev = NULL;
        Item *curr = head;
        for (int j = 0; j < dim - h && curr->next; ++j) {
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
        }
    }
    
    return head;
}
