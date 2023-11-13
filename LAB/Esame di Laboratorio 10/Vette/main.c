#include "list.h"
 
#include <stdlib.h>
extern int ContaVette(const Item* i);
Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    int v[] = { 7,2,5,4 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    
    printf("num vette = %d\n", ContaVette(list));
    
    ListDelete(list);
    
    return EXIT_SUCCESS;
}
