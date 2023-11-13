#include <stdio.h>
#include <stdlib.h>
extern void InsertionSort(int *v, size_t v_size);
void PrintStdoutVector(int *v, size_t v_size){
    printf("{");
    for (size_t i = 0; i != v_size-1; ++i) {
        printf("%d, ",v[i]);
    }
    printf("%d}\n", v[v_size-1]);
}
int main(void) {
    {
        int v[] ={1, 12, 5, 4, 3, 2, 13  };
        size_t size = sizeof(v)/sizeof(int);
        PrintStdoutVector(v, size);
        InsertionSort(v, size);
        PrintStdoutVector(v, size);
    }
    
    return 0;
}
