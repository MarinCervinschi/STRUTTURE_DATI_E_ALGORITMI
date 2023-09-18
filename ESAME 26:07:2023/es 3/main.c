#include "doublelist.h"
#include "diff_dlist.h"
#include <stdlib.h>
 
Item *DListCreateFromVector(const ElemType *v, size_t v_size) {
    Item *list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    ElemType v[] = {1,1,1,1};
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = DListCreateFromVector(v, v_size);
    DListWriteStdout(list);
    
    ElemType v1[] = { 9 };
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    Item *list1 = DListCreateFromVector(v1, v1_size);
    DListWriteStdout(list1);
    
    DListWriteStdout(DListDiff(list, list1));
    
    DListDelete(list1);
    DListDelete(list);
    return EXIT_SUCCESS;
}
