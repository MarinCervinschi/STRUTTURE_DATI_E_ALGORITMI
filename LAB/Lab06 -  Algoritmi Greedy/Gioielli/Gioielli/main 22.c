#include <stdio.h>
#include <stdlib.h>
#include "gioielli.h"
int main(void) {
    
    size_t ret_size = 0;
    
    Gioiello *ret = CompraGioielli("gioielli_1.txt", 121, &ret_size);
    
    free(ret);
    
    return 0;
}
