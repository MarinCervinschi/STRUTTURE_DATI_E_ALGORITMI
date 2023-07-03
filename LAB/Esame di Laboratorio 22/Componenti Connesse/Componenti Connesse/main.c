#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "cc.h"
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
 
void PrintStdoutVector(ElemType *v, int v_size){
    printf("{");
    for (int i = 0; i != v_size-1; ++i) {
        printf("%d, ",v[i]);
    }
    printf("%d}\n", v[v_size-1]);
}
int main(void) {
    Item *list = ListLoad("data.txt");
 
    ListWriteStdout(list);
    ElemType v[] = {7, 8, 0, 4, 6};
    PrintStdoutVector(v, 5);
    

    int ret = 0;
    ret = ComponentiConnesse(list, v, 5);
    ListDelete(list);
   
    return EXIT_SUCCESS;
}
