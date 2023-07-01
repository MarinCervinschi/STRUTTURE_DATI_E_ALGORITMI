#include <stdlib.h>
#include <stdio.h>
extern char* SolveSuperstring(const char **v, size_t v_size);
int main(void) {
    {
        const char *string1[] = {"ADGTATTTA", "TATTTAATCCCGTGC", "CGTGCTTAATA", "CGTA", "CGTA", "GATCCCTG"};
        
        char *res;
        res = SolveSuperstring(string1, 6);
        printf("La SuperStringa di STRING1 è: %s\n" , res);
        free(res);
    }
    {
        const char *dizionario[] = {"ABCDH", "DHE", "BCDH", "HEF"};
        
        char *res;
        res = SolveSuperstring(dizionario, 4);
        printf("La SuperStringa di DIZIONARIO è: %s\n" , res);
        
        free(res);
    }
    return 0;
}
