#include <stdio.h>
#include "elemtype.h"
#include "list.h"

extern Item *ListLoad(const char *filename);
extern Item *Diff(const Item *i1, const Item *i2);
int main(void) {

    Item *i1, *i2, *i3;

    i1 = ListLoad("data_00.txt");
    i2 = ListLoad("data_01.txt");

    i3 = Diff(i1, i2);
    ListWriteStdout(i3);
    
    ListDelete(i1);
    ListDelete(i2);
    ListDelete(i3);
    return 0;
}
