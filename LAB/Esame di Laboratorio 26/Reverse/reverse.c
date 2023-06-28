#include "reverse.h"
#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
int ListLeng(Item *list){
    Item *l = list;
    int n = 0;
    while (l) {
        n++;
        l = l->next;
    }
    return n-1;
}
Item* Reverse(Item *list, int left){
    int len = ListLeng(list);
    if(left >= len){
        return list;
    }
    
    Item *tmp = list;
    if(left > 0){
        int count = 0;
        while (tmp) {
            if(count+1 == left){
                --len;
                break;
            }
            count++; --len;
            tmp = tmp->next;
        }
    }else{
        Item *tmp0 = NULL;
        ElemType d = 99;
        tmp0 = ListInsertBack(tmp0, &d);
        tmp0->next = list;
        int g = 1;
        while (tmp0) {
                Item *tmp1 = tmp0;
                while (tmp1) {
                    if(tmp1->next == NULL){
                        tmp1->next = tmp0->next;
                        tmp0->next = tmp1;
                        Item *tmp2 = tmp0->next;
                        while (tmp2) {
                            if(tmp2->next == tmp1){
                                tmp2->next = NULL;
                                break;
                            }
                            tmp2 = tmp2->next;
                        }
                        break;
                    }
                    tmp1 = tmp1->next;
                }
                --len;
                
                tmp0 = tmp0->next;
            if(g == 1){
                tmp = tmp0;
                g = 0;
            }
            }
        ListDelete(tmp0);
        return tmp;
    }
    
    while (len != 0) {
            Item *tmp1 = tmp;
            while (tmp1) {
                if(tmp1->next == NULL){
                    tmp1->next = tmp->next;
                    tmp->next = tmp1;
                    Item *tmp2 = tmp->next;
                    while (tmp2) {
                        if(tmp2->next == tmp1){
                            tmp2->next = NULL;
                            break;
                        }
                        tmp2 = tmp2->next;
                    }
                    break;
                }
                tmp1 = tmp1->next;
            }
            --len;
            
            tmp = tmp->next;
        }
    
    
    return list;
}

