#include <stdio.h>
#include "elemtype.h"
#include "doublelist.h"
#include <stdlib.h>
extern Item *ConcatenaN(Item **v, size_t v_size);
Item *DListCreateFromVector(const ElemType *v, size_t v_size) {
   Item *list = DListCreateEmpty();
   for (size_t i = 0; i < v_size; ++i) {
       list = DListInsertBack(list, &v[i]);
   }
   return list;
}
int main(void) {

    ElemType v1[] = { 1,2,3 };
    size_t v_size = sizeof(v1) / sizeof(ElemType);
    Item *list = DListCreateFromVector(v1, v_size);
    DListWriteStdout(list);
    
    ElemType v2[] = { 4,5,6 };
    size_t v2_size = sizeof(v2) / sizeof(ElemType);
    Item *list1 = DListCreateFromVector(v2, v2_size);
    DListWriteStdout(list1);


    Item *v[] = { list, NULL, list1};
   
    Item *ret = ConcatenaN(v, 3);

    DListWriteStdout(ret);
    

    return 0;
}
