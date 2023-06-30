#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
#include "doublelist.h"
#include "sum_dlist.h"
extern Item *ListLoad(const char *filename);
int main(void) {

    Item *i1, *i2, *i3;

    i1 = ListLoad("data_00.txt");
    DListWriteStdout(i1);
    
    i2 = ListLoad("data_01.txt");
    DListWriteStdout(i2);
    
    i3 = DListSum(i1, i2);
    DListWriteStdout(i3);
    
    DListDelete(i1);
    DListDelete(i2);
    DListDelete(i3);
    return 0;
}
