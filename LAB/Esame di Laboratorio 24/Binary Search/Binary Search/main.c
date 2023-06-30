#include <stdio.h>
#include <stdlib.h>
extern int BinarySearch(const int *v, size_t v_size, int value);
int main(void) {
  
    int g[] = { 2,3,4,6};
    int ret = 0;
    ret = BinarySearch(g, 4, 5);
    if(ret == -1){
        printf("Error!! -> Il numero cercato non appartiene al vettore\n");
        return 0;
    }
    printf("Il numero cercato è in posizione: %d\n", ret);
    return 0;
}
