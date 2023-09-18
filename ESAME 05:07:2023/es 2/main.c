#include <stdlib.h>
#include <stdbool.h>
extern bool* OptimalIllumination(int M, int R, const int *light, size_t light_size);
int main(void) {
   
    int light[] = {1, 2, 3, 7, 8, 9, 13, 14, 15, 17};
    bool *ret = NULL;
    ret = OptimalIllumination(19, 2, light, 10);
    return 0;
}
