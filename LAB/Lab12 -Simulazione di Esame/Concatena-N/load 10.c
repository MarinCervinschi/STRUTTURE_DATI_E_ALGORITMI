#include <stdio.h>
#include "elemtype.h"
#include "doublelist.h"
Item *ListLoad(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        Item *list_null = DListCreateEmpty();
        return list_null;
    }
    Item *list_ret = DListCreateEmpty();
    
    ElemType tmp = 0;
    while (ElemRead(f, &tmp) != EOF) {
        list_ret = DListInsertHead(&tmp, list_ret);
    }
    
    fclose(f);
    return list_ret;
}

