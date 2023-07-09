#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
Item *ListLoad(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        Item *list_null = ListCreateEmpty();
        return list_null;
    }
    Item *list_ret = ListCreateEmpty();
    
    ElemType *tmp = calloc(1, sizeof(ElemType));
    while (fscanf(f, "%[^\n]", tmp->name) == 1) {
        list_ret = ListInsertBack(list_ret, tmp);
        fseek(f, 1, SEEK_CUR);
    }
    free(tmp);
    fclose(f);
    return list_ret;
}

