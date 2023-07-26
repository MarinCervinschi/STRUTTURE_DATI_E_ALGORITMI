#include "diff_dlist.h"
Item *DListCopy(const Item *i) {
    Item *list_copy = DListCreateEmpty(); // Creo una lista vuota (NULL pointer)
 
    // Itero tutti gli elementi della lista da copiare
    for (; !DListIsEmpty(i); i = DListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = DListInsertBack(list_copy, DListGetHeadValue(i));
    }
 
    return list_copy;
}
int NumDiff(int a, int b, int *p){
    a -= *p;
    *p = 0;
    if( a - b < 0){
        *p = 1;
        return 10 - b + a;
    }else{
        return a - b;
    }
}
Item* DListDiff(const Item *i1, const Item *i2){
    if(!i1 && !i2){
        return NULL;
    }
    if(!i1){
        return DListCopy(i2);
    }
    if(!i2){
        return DListCopy(i1);
    }
    while (i1->next) {
        i1 = i1->next;
    }
    while (i2->next) {
        i2 = i2->next;
    }
    
    Item *diff = NULL;
    int p = 0;
    while (1) {
        if(!i1 && !i2){
            break;
        }
        int a = 0, b =0 ;
        if(i1){
            a = i1->value;
            i1 = i1->prev;
        }
        if(i2){
            b = i2->value;
            i2 = i2->prev;
        }
        const ElemType iter = NumDiff(a, b, &p);
        diff = DListInsertHead(&iter, diff);
    }
    
    return diff;
}
