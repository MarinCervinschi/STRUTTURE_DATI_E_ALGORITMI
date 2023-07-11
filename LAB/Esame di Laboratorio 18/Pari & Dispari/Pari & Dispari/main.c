#include "list.h"
#include <stdlib.h>
extern Item *PariDispari(Item *i);
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
    {
        Item *list = ListLoad("data.txt");
        ListWriteStdout(list);
    
        list = PariDispari(list);
        ListWriteStdout(list);
        ListDelete(list);
    }
    printf("\n");
    {
        Item *list = ListLoad("data1.txt");
        
        ListWriteStdout(list);
        list = PariDispari(list);
        ListWriteStdout(list);
        ListDelete(list);
    }
    return EXIT_SUCCESS;
}
