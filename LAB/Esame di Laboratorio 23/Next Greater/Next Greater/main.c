#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "next_greater.h"
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
 
    ListWriteStdout(list);
    
    ElemType *ret;
    size_t num = 0;
    ret = NextGreater(list, &num);
    
 
    ListDelete(list);
    free(ret);
    return EXIT_SUCCESS;
}
