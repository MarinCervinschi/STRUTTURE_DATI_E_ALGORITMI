#include <stdio.h>
extern int AToI(const char *str);
int main(void) {
   
    int ret = 0;
    ret = AToI("99");
    
    printf("Il numero str è: %d\n", ret);
    
    return 0;
}
