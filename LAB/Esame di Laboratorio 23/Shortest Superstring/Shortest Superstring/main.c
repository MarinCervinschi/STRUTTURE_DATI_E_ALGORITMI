#include <stdlib.h>
extern char* SolveSuperstring(const char **v, size_t v_size);
int main(void) {
   
    const char *dizionario[] = {"ADGTATTTA", "TATTTAATCCCGTGC", "CGTGCTTAATA", "CGTA", "CGTA", "GATCCCTG"};
    const char *kk[] = {"ABCDH", "DHE", "BCDH", "HEF"};
    
    char *res;
    res = SolveSuperstring(dizionario, 6);
    
    return 0;
}
