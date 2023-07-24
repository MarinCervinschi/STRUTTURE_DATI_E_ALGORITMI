#include <stdio.h>
#include "elemtype.h"
#include "list.h"
extern Item* BucketSort(Item *l);
Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}
int main(void) {
    int v[] = { 7,5,2,4};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);

    
    list = BucketSort(list);
    ListWriteStdout(list);
    
    ListDelete(list);
    return 0;
}
