#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include "shift.h"
extern Item *ListLoad(const char *filename);
int main(void) {

    Item *i1;

    i1 = ListLoad("data_00.txt");
    ListWriteStdout(i1);
    
    i1 = ShiftN(i1, 4);
    ListWriteStdout(i1);
    
    ListDelete(i1);
    return 0;
}
