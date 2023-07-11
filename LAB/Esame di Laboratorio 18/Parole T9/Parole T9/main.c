#include <stdio.h>
extern int ParoleT9(const char *str);
int main(void) {
    
    int ret = 0;
    ret = ParoleT9("54");
    printf("%d soluzioni\n", ret);
    return 0;
}
