#include <stdio.h>
#include "elemtype.h"
#include "doublelist.h"
#include <stdlib.h>
extern Item *ConcatenaN(Item **v, size_t v_size);
extern Item *ListLoad(const char *filename);
int main(void) {

    Item *i1, *i2, *i3, *i4;

    i1 = ListLoad("data_00.txt");
    i2 = ListLoad("data_01.txt");
    i4 = ListLoad("data_02.txt");

    Item *v[] = { i1, i2, NULL};
    
    i3 = ConcatenaN(v, 3);

    DListWriteStdout(i3);
    DListDelete(i1);
    DListDelete(i2);
    DListDelete(i3);
    DListDelete(i4);
    return 0;
}
