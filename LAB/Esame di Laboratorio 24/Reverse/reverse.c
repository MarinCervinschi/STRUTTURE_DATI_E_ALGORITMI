#include "reverse.h"
#include <stdlib.h>
int ListLenght(Item *list){
    Item *tmp = list;
    int count = 0;
    while (tmp) {
        ++count;
        tmp = tmp->next;
    }
    return count-1;
}
Item* Reverse(Item *list, int right){
    if (right <= 1 || ListIsEmpty(list)) {
        return list;
    }
    
    int len = ListLenght(list);
    if(right > len){
        right = len +1;
    }

    
    for (int j = 1; j != right; ++j) {
        
        Item *next = NULL;
        Item *curr = list;
        Item *prev = NULL;
        
        for (int i = 0; i != right-j; ++i) {
            next = curr->next;
            
            curr->next = next->next;
            next->next = curr;
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
    }
    
    return list;
}
