#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
void deallocateList(Item* head) {
    while (head != NULL) {
        Item* temp = head;
        head = head->next;
        free(temp);
    }
}
extern Item *ListLoad(const char *filename);
extern Item* CopiaDaN(const Item* i, int n);
int main(void) {

    Item *i1, *i2;

    i1 = ListLoad("data_00.txt");
    ListWriteStdout(i1);
    
    i2 = CopiaDaN(i1, 2);
    ListWriteStdout(i2);
    
    ListDelete(i1);
    ListDelete(i2);
    return 0;
}
