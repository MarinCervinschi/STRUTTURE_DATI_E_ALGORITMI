#include <stdio.h>
extern int CombinaMonete(int b, const int* m, size_t m_size);
int main(void) {
   
    int m[] = {1, 2, 50, 10, 5, 20};
    int sol = 0;
    sol = CombinaMonete(4, m, 6);
    return 0;
}
