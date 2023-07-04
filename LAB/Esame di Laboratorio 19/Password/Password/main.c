#include <stdio.h>
extern int Password(const char *str, int n);
int main(void) {
    int n = 0;
    n = Password("pio", 3);
    printf("%d possibilità\n", n);
    return 0;
}
