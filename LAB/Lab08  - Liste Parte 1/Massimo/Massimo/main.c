#include <stdio.h>
#include "elemtype.h"
#include "list.h"

extern Item *ListLoad(const char *filename);
const ElemType *MaxElement(const Item *i);
int main(void) {

    Item *i1;

    i1 = ListLoad("data_00.txt");
    ListWriteStdout(i1);
    
    const ElemType *max = MaxElement(i1);
    printf("L'ElemType massimo di i1 = %d\n", *max);
    
    ListDelete(i1);
    return 0;
}
