#include <stdio.h>
extern void BrickSort(int* v, size_t v_size);
void PrintStdoutVector(int *v, int v_size){
    printf("{");
    for (int i = 0; i != v_size-1; ++i) {
        printf("%d, ",v[i]);
    }
    printf("%d}\n", v[v_size-1]);
}
int main(void) {
    
    int v[] = { 9, 2, 6, 3, 8, 1, 7, 4};
    PrintStdoutVector(v, 8);
    
    BrickSort(v, 8);
    PrintStdoutVector(v, 8);
    
    
    return 0;
}
