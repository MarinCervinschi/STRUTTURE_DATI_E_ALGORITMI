#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

extern int KthLeast(const int* v, size_t n, int k);
int main(void) {
    
    ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
    
    int Kth = 0;
    Kth = KthLeast(v, 10, 3);
    printf("il 3 numero più piccolo è %d\n", Kth);
    
    return 0;
}
