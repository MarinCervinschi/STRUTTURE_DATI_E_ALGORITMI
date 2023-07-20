#include <stdio.h>

extern int OptimalSubarray(const int *v, size_t n);
void PrintStdoutVector(int *v, int v_size){
    if (!v || v_size == 0) {
        return;
    }
    printf("{");
    for (int i = 0; i != v_size-1; ++i) {
        printf("%d, ",v[i]);
    }
    printf("%d}\n", v[v_size-1]);
}
int main(void) {
    {
        int v[] = {  };
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = {  1, 2, 3, 4, 5, 6};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { 1, 2, 1, -100, 5, 6};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { -100, 5, 6, -5, 1, 2, 1 };
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { -100, 5, 6, -3, 1, 2, 1 };
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { -100, 5, 6, -3, 1, 2, 1, 3};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { -1, -2, -3, -4, -5, -6};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = { 1, 1, 1, -5, 1, 1, 1, -5, 1, 1, 1};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
        printf("\n");
    }
    {
        int v[] = {  1, 1, 1, -5, -1, -1, -1, -5, -1, -1, -1};
        size_t size = sizeof(v) / sizeof(int);
        PrintStdoutVector(v, (int)size);
        
        printf("%d è la somma massima dei sottovettori ottimi di elementi contigui\n", OptimalSubarray(v, size));
    }
    return 0;
}
