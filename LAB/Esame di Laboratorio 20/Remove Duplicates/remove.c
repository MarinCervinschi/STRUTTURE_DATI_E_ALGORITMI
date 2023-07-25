#include "remove.h"
#include <stdlib.h>
#include "elemtype.h"
Item *FindNext(Item *i){
    while (i->next) {
        if(ElemCompare(&i->value, &i->next->value) != 0){
            break;
        }
        i = i->next;
    }
    return i ? i->next : i;
}
Item *RemoveDuplicates(Item* i){
    if(!i){
        return NULL;
    }
    
    Item *head = i;
    for (Item *tmp = i->next; tmp; tmp = tmp->next) {
        if(ElemCompare(&tmp->value, &head->value) == 0){
            head->next = FindNext(tmp);
            
            while (tmp != head->next) {
                Item *j = tmp;
                tmp = tmp->next;
                free(j);
            }
            
            tmp = head;
        }else{
            head = head->next;
        }
        if (!tmp->next) {
            break;
        }
    }
    
    return i;
}
