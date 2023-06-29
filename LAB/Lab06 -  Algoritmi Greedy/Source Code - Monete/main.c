#include <stdlib.h>

extern int *Monete(int *tagli, size_t tagli_size, int budget);

int main(void) {
    {
        int tagli[] = { 50, 20, 10, 5, 2, 1 };
        int *res = Monete(tagli, sizeof(tagli) / sizeof(int), 126);
        free(res);
    }

    {
        int tagli[] = { 50, 20, 6, 5, 2, 1 };
        int *res = Monete(tagli, sizeof(tagli) / sizeof(int), 10);
        free(res);
    }


    return 0;
}