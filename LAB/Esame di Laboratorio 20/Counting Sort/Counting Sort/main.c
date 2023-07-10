#include <stdlib.h>
#include <stdio.h>
extern void CountingSort(int *v, size_t v_size);
void PrintStdoutVector(int *v, int v_size){
    printf("{");
    for (int i = 0; i != v_size-1; ++i) {
        printf("%d, ",v[i]);
    }
    printf("%d}\n", v[v_size-1]);
}
int main(void) {
    {
        int v[] ={3, 6, 2, 9, 0, 7, 1, -4, 8 };
        PrintStdoutVector(v, 9);
        CountingSort(v, 9);
        PrintStdoutVector(v, 9);
    }
    
    return 0;
}
