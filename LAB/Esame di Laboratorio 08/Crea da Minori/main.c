#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
extern Item *ListLoad(const char *filename);
extern Item* CreaDaMinori(const Item* i, int v);
int main(void) {

    Item *i1, *i2;

    i1 = ListLoad("data_00.txt");
    ListWriteStdout(i1);
    
    i2 = CreaDaMinori(i1, -1);
    ListWriteStdout(i2);
    
    ListDelete(i1);
    ListDelete(i2);
    return 0;
}
