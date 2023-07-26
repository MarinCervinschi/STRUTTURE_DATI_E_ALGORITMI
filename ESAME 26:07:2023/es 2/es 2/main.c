#include <stdio.h>
extern int* SolarCut(int A, size_t *sol_size);
int main(void) {
    size_t size = 0;
    int *v = SolarCut(12, &size);
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
