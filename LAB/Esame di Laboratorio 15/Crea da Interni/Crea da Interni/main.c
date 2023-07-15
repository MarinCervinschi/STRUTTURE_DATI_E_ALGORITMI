#include "list.h"
 
#include <stdlib.h>
extern Item *CreaDaInterni(const Item *i, double r);
Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; i += 2) {
        list = ListInsertBack(list, &(ElemType){v[i], v[i + 1]});
    }
    return list;
}
 
int main(void) {
    //          x1 y1 x2 y2 x3 y3 x4 y4 x5 y5
    int v[] = { 12, 2, 2, 3, 34, 37, 4, -2};
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);
 
    ListWriteStdout(list);
    Item *ret;
    ret = CreaDaInterni(list, 5);
    ListWriteStdout(ret);
    
    ListDelete(list);
    ListDelete(ret);
 
    return EXIT_SUCCESS;
}
