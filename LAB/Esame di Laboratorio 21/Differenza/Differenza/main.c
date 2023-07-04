#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "differenza.h"
Item *ListLoad(const char *filename) {
    FILE *f;
    f = fopen(filename, "r");
 
    if (!f) {
        return NULL;
    }
 
    Item *i = ListCreateEmpty();
    while (1) {
        ElemType tmp;
        if (1 != ElemRead(f, &tmp)) {
            break;
        }
        i = ListInsertHead(&tmp, i);
    }
 
    fclose(f);
    return i;
}
 
int main(void) {
    Item *list = ListLoad("data.txt");
    Item *list1 = ListLoad("data1.txt");
 
    ListWriteStdout(list);
    ListWriteStdout(list1);
    
    Item *diff = Differenza(list, list1);
    ListWriteStdout(diff);
    

    ListDelete(list);
    ListDelete(list1);
    ListDelete(diff);
   
    return EXIT_SUCCESS;
}
