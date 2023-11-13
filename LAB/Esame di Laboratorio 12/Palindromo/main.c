#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern bool IsPalindromo(const char* str);
int main(void) {
    IsPalindromo("") ? printf("true\n") : printf("false\n");
    return 0;
}
