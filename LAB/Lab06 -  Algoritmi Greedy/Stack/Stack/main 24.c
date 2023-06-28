#include <stdio.h>
#include "stacks.h"
#include <stdlib.h>
int main(void) {
    
    unsigned n1[] = {1, 1, 1, 2, 3};
    unsigned n2[] = {2, 3, 4};
    unsigned n3[] = { 1, 4, 5, 2};
    
    Stack s[3] = { {n1 , 5 }, { n2, 3 }, {n3, 4 } };
    
    unsigned ret = 0;
    ret = MaxSumNStack(s, 3);


    return 0;
}
