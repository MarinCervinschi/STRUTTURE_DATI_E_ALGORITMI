#include "sum_dlist.h"
#include "doublelist.h"
#include <stdlib.h>

Item *ListInvert(const Item * i1){
    Item *i1_copy = NULL;
    for (const Item *tmp = i1; tmp; tmp = tmp->next) {
        i1_copy = DListInsertHead(&tmp->value, i1_copy);
    }
    return i1_copy;
}
int Rest(const Item *i1, const Item *i2){
    int n1, n2;
    if(!i1){
        n1 = 0;
    }else{
        n1 = i1->value;
    }
    if(!i2){
        n2 = 0;
    }else{
        n2 = i2->value;
    }

    int ret = n1 + n2;
    if(ret < 10){
        return 0;
    }
    while (ret > 10) {
        ret /= 10;
    }
    
    return ret;
}
int Num(const Item *i1, const Item *i2){
    int n1, n2;
    if(!i1){
        n1 = 0;
    }else{
        n1 = i1->value;
    }
    if(!i2){
        n2 = 0;
    }else{
        n2 = i2->value;
    }

    int ret = n1 + n2;
    return ret % 10;
}

Item *DListSum(const Item *i1, const Item *i2){
    if(DListIsEmpty(i1) && DListIsEmpty(i2)){
        return NULL;
    }
    if(DListIsEmpty(i1)){
        Item *ret = NULL;
        for (const Item *tmp = i2; tmp; tmp = tmp->next) {
            ret = DListInsertBack(ret, &tmp->value);
        }
        return ret;
    }
    if(DListIsEmpty(i2)){
        Item *ret = NULL;
        for (const Item *tmp = i1; tmp; tmp = tmp->next) {
            ret = DListInsertBack(ret, &tmp->value);
        }
        return ret;
    }
    Item *ret = NULL;
    int k = 0;
    Item *i1_copy = ListInvert(i1);
    
    Item *i2_copy = ListInvert(i2);
    
    while (1) {
        if (DListIsEmpty(i1_copy) && DListIsEmpty(i2_copy)) {
            break;
        }
        k += Num(i1_copy, i2_copy);
        
        if(k < 10){
            ret = DListInsertHead(&k, ret);
            k = Rest(i1_copy, i2_copy);
        }else{
            int l = k /10;
            k %= 10;
            ret = DListInsertHead(&k, ret);
            k = l;
        }
        
        if(i1_copy != NULL){
            i1_copy = i1_copy->next;
        }
        if(i2_copy != NULL){
            i2_copy = i2_copy->next;
        }
    }
    
    
    return ret;
}
