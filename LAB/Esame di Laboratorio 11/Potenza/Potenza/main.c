#include <stdio.h>
extern int Potenza(int a, int b);

int main(void) {
    
    printf("0^0 = %d\n", Potenza(0, 0));
    printf("0^3 = %d\n", Potenza(0, 3));
    printf("5^0 = %d\n", Potenza(5, 0));
    printf("2^5 = %d\n", Potenza(2, 5));

    
    
    return 0;
}
