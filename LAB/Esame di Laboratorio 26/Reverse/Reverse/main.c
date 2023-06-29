#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include "reverse.h"
extern Item *ListLoad(const char *filename);
int main(void) {

    Item *i1, *i2;

    i1 = ListLoad("data_00.txt");
    ListWriteStdout(i1);
    
    i2 = Reverse(i1, 0);
    ListWriteStdout(i2);
    
    ListDelete(i1);
    
    return 0;
}
