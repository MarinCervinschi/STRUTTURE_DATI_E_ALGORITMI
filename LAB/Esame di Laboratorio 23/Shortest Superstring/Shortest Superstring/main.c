#include <stdlib.h>
extern char* SolveSuperstring(const char **v, size_t v_size);
int main(void) {
   
    const char *dizionario[] = {"ABCDH", "DHE", "BCDH", "HEF"};
    
    char *res;
    res = SolveSuperstring(dizionario, 4);
    
    return 0;
}
