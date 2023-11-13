#include "list.h"
 
#include <stdlib.h>
extern Item* Sum(const Item *i1, const Item *i2);
Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    int v[] = { 2, 2, 8, 7, 3, 7, 4, 1, 8, 2, 4};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    
    printf("+\n");
    
    int v1[] = {1, 8, 7, 3, 7, 4, 1, 8, 2, 4};
    size_t v1_size = sizeof(v1) / sizeof(int);
    Item *list1 = ListCreateFromVector(v1, v1_size);
    ListWriteStdout(list1);
    
    printf("=\n");
    
    Item *ret;
    ret = Sum(list, list1);
    ListWriteStdout(ret);
    
    ListDelete(ret);
    ListDelete(list);
    ListDelete(list1);
    return 0;
}
