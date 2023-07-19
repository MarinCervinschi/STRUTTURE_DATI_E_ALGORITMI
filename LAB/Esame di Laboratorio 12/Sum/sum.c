#include "list.h"
 
#include <stdlib.h>
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
    while (ret >= 10) {
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
Item *ListCopy(const Item *i) {
    Item *list_copy = ListCreateEmpty(); // Creo una lista vuota (NULL pointer)
 
    // Itero tutti gli elementi della lista da copiare
    for (; !ListIsEmpty(i); i = ListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = ListInsertBack(list_copy, ListGetHeadValue(i));
    }
 
    return list_copy;
}
Item* Sum(const Item *i1, const Item *i2){
    if(!i1 && !i2){
        return NULL;
    }
    if(!i1){
        return ListCopy(i2);
    }
    if(!i2){
        return ListCopy(i1);
    }
    Item *ret = NULL;
    int k = 0;
    
    while (1) {
        if(!i1 && !i2){
            break;
        }
        k += Num(i1, i2);
                
        if(k < 10){
            ret = ListInsertBack(ret, &k);
            
            k = Rest(i1, i2);
            if ( k != 0 && (!i1->next && !i2->next) ) {
                ret = ListInsertBack(ret, &k);
            }
        }else{
            int l = k /10;
            k %= 10;
            ret = ListInsertHead(&k, ret);
            k = l;
            if ( k != 0 && (!i1->next && !i2->next) ) {
                ret = ListInsertBack(ret, &k);
            }
        }
        if(i1){
            i1 = i1->next;
        }
        if(i2){
            i2 = i2->next;
        }
    }
    
    return ret;
}
