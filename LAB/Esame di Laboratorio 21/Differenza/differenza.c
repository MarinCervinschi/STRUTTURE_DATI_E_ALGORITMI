#include "differenza.h"
#include <stdlib.h>
Item *Copia(const Item *i1){
    Item *tmp = NULL;
    while (i1) {
        tmp = ListInsertBack(tmp, &i1->value);
        i1 = i1->next;
    }
    return tmp;
}

const ElemType Num(int s,int m, int *p){
    s -= *p;
    *p = 0;
    if(s < m){
        *p = 1;
        s += 10;
    }
    return (s - m) + '0';
}
Item *Differenza(const Item *i1, const Item *i2){
    if(!i1 && !i2){
        return NULL;
    }
    if(!i1){
        return Copia(i2);
    }
    if(!i2){
        return Copia(i1);
    }
    Item *diff = NULL;
    int p = 0;
    while (1) {
        if(!i1 && !i2){
            break;
        }
        
        ElemType s =0, m = 0;
        if(i1){
            s = atoi(&i1->value);
            i1 = i1->next;
        }
        if(i2){
            m = atoi(&i2->value);
            i2= i2->next;
        }
        
        const ElemType iter = Num(s, m, &p);
        diff = ListInsertBack(diff, &iter);
    }
    return diff;
}
