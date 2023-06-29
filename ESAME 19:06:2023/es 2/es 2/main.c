#include <stdio.h>

extern int OptimalSubarray(const int *v, size_t n);
int main(void) {
    
    int v[] = { 1, 2, 1, -100, 5, 6};
    
    int ret = 0;
    ret = OptimalSubarray(v, 6);
    return 0;
}
