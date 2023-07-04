#include "differenza.h"
#include <stdlib.h>
Item *Copia(const Item *i1){
    Item *tmp = NULL;
    while (i1) {
        tmp = ListInsertHead(&i1->value, tmp);
        i1 = i1->next;
    }
    return tmp;
}
Item *Differenza(const Item *i1, const Item *i2){
    if
}
