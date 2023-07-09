#include <stdio.h>
#include "list.h"
#include "elemtype.h"
extern Item *ListLoad(const char *filename);
extern Item *Sort(Item *i);
extern Item *RemoveDuplicates(Item* i);
int main(void) {
    
    Item *list = ListLoad("data.txt");
    
    list = Sort(list);
    list = RemoveDuplicates(list);
    
    FILE *f = fopen("Data1.txt", "w");
    
    ListWrite(list, f);
    
    
    ListDelete(list);
    return 0;
}

