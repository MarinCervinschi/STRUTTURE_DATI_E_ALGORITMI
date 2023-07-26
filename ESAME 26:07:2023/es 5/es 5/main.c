#include <stdio.h>
extern void CocktailSort(int *v, size_t v_size);
void Print(int *v, size_t v_size){
    for (size_t i = 0; i < v_size; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
int main(void) {
    int v[] = { 9 ,6 ,4, 8 ,2, 0,-4, 1};
    size_t size = sizeof(v)/sizeof(int);
    Print(v, size);
    CocktailSort(v, size);
    Print(v, size);
    return 0;
}
