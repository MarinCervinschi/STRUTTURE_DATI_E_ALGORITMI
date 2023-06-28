#include <stdbool.h>
#include <stdlib.h>
#include "elemtype.h"
#include "list.h"
#include <string.h>
const ElemType *MaxElement(const Item *i){
    if (ListIsEmpty(i)) {
        return NULL;
    }
    const ElemType *max = ListGetHeadValue(i);
    for (const Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        if (ElemCompare(max, ListGetHeadValue(tmp)) < 0) {
            max = ListGetHeadValue(tmp);
        }
    }
    return max;
}
Item *Sort(Item *i){
    const ElemType *min;
    Item *list_ret = ListCreateEmpty();
    int pos = 0, lung_list = 0;
    
    //trovo la lunghezza della lista
    for (Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)){
        ++lung_list;
    }
    //alloco la memoria per un vettore di bool
    bool *h = calloc(lung_list, sizeof(bool));
    
    for (Item *tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        int j = 0;
        for (Item *tmp1 = i; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)){
            if(j == 0){
                min = MaxElement(i);
            }
            if(ElemCompare(ListGetHeadValue(tmp1), min) < 0 && !h[j]){
                min = ListGetHeadValue(tmp1);
                pos = j;//la posizione del minimo
            }
            ++j;
        }
        h[pos] = true; //aggiorno il vettore
        list_ret = ListInsertBack(list_ret, min);
    }
   
    free(h);
    return list_ret;
}
