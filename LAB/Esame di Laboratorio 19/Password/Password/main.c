#include <stdio.h>
extern int Password(const char *str, int n);
int main(void) {
    int n = 0;
    n = Password("a1", 2);
    printf("%d possibilità\n", n);
    return 0;
}
