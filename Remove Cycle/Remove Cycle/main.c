#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "no_cycle.h"

Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}


int main(void) {
    int v[] = { 1, 2, 3, 4};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);

    Item *list2 = ListCreateEmpty();

    list2 = list->next;
    
    list->next->next->next->next = list->next; // Create a cycle
    
    RemoveCycle(list);
    ListWriteStdout(list);
    
    ListDelete(list);
}
