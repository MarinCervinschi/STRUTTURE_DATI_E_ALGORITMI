#include "doublelist.h"
#include <stdlib.h>
#include "pulce.h"

Item *DListCreateFromVector(const ElemType *v, size_t v_size) {
    Item *list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    ElemType v[] = { 200,-3,-2,1,0,5,-12,3 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = DListCreateFromVector(v, v_size);
    
    DListWriteStdout(list);
    
    const Item *ret = list;
    const Item *tmp = ret->next->next;
    ret = CalcolaPercorso(list, 41);
    
    printf("%d\n",ret->value);
    
    DListDelete(list);
    
    return EXIT_SUCCESS;
    
}
