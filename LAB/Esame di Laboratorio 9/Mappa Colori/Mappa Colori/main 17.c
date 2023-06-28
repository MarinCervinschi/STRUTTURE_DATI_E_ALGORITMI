#include <stdio.h>
#include "colora.h"
#include <stdbool.h>
int main(void) {
  
    bool k[] = {1,1,1,
                1,1,0,
                1,0,1
    };
    struct Matrix m = { .size = 3, .data = k };
    const char c[] = { 'r', 'v'};
    
    int ret = 0;
    ret = MappaColori(&m, c, 2);
    return 0;
}
