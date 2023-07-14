#include "domino.h"
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    const Tessera t[] = { { .val1 = 5, .val2 = 3 }, { .val1 = 5, .val2 = 6 }, { .val1 = 5, .val2 = 4 }, { .val1 = 6, .val2 = 2 } };
    size_t size = sizeof(t) / sizeof(Tessera);
    size_t ret_size = 0;
    
    Placing *ret = NULL;
    ret = Domino(t, size, &ret_size);
    
    
    free(ret);
    return 0;
}
