#include <stdio.h>
#include "elemtype.h"
#include "list.h"
Item *ListLoad(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        Item *list_null = ListCreateEmpty();
        return list_null;
    }
    Item *list_ret = ListCreateEmpty();
    
    ElemType tmp = 0;
    while (ElemRead(f, &tmp) != EOF) {
        list_ret = ListInsertHead(&tmp, list_ret);
    }
    
    fclose(f);
    return list_ret;
}
int main(void) {
    Item *list;
    list = ListCreateEmpty();
    
    list = ListLoad("data_00.txt");
    
    
    ListDelete(list);
    return 0;
}
