#include <stdlib.h>
extern int* RisolviProdotto(int n, const int *s);
int main(void) {
    
    int s[] = {1, 2, 5, 8, 9, 16, 18, 40, 45};
    
    int *ret;
    ret = RisolviProdotto(3, s);
    
    free(ret);
    return 0;
}
