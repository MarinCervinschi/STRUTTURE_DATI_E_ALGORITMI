#include "list.h"
#include "reverse.h"
#include <stdlib.h>

Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    
    ListWriteStdout(Reverse(list, 1));
    ListDelete(list);
    return EXIT_SUCCESS;
}
    
