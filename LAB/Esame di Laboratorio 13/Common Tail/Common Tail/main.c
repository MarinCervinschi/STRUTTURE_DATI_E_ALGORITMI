#include "list.h"
 
#include <stdlib.h>
extern const Item* CommonTail(const Item* i1, const Item* i2);
Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    int v[] = { 7,2,5,4};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    const Item *ret = NULL;
    ret = CommonTail(list, list->next);
    
    ListWriteStdout(ret);
    
    ListDelete(ret);
    ListDelete(list);
    return 0;
}
