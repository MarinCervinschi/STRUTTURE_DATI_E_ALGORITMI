#include "list.h"
#include "elemtype.h"
#include <stdlib.h>
#include <math.h>
int Distanza(const Item *i){
    return sqrt( (i->value.x)*(i->value.x) + (i->value.y)*(i->value.y) );
}
Item *CreaDaInterni(const Item *i, double r){
    if (!i || r == 0) {
        return NULL;
    }
    Item *ret = NULL;
    while (i) {
        if(Distanza(i) <= r){
            ret = ListInsertBack(ret, &i->value);
        }
        i = i->next;
    }
    return ret;
}
