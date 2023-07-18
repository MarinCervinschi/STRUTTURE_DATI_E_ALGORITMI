#include "doublelist.h"
#include <stdlib.h>
#include "pulce.h"
Item *DListLoad(const char *filename) {
    FILE *f;
    f = fopen(filename, "r");
 
    if (!f) {
        return NULL;
    }
 
    Item *i = DListCreateEmpty();
    while (1) {
        ElemType tmp;
        if (1 != ElemRead(f, &tmp)) {
            break;
        }
        i = DListInsertHead(&tmp, i);
    }
 
    fclose(f);
    return i;
}
 
int main(void) {
    Item *list = DListLoad("data.txt");
 
    DListWriteStdout(list);
 
    const Item *ret = list;
    const Item *tmp = ret->next->next;
    ret = CalcolaPercorso(tmp, 13);
    
    DListDelete(list);
 
    return EXIT_SUCCESS;
}
