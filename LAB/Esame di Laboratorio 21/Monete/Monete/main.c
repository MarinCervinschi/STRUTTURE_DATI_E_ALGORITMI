#include <stdio.h>
extern int CombinaMonete(int b, const int* m, size_t m_size);
int main(void) {
   
    int m[] = {2, 50, 10, 5, 20};
    int sol = 0;
    sol = CombinaMonete(36, m, 5);
    printf("\n%d soluzioni\n", sol);
    return 0;
}
