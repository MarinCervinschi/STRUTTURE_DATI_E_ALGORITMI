#include <stdio.h>
#include "torrecartoni.h"
#include <stdlib.h>

int main(void) {
    
    Cartone n1 = { 10, 10, 12};
    Cartone n2 = { 25, 20, 40};
    Cartone n3 = { 9, 3, 5};

    Cartone vettore[3];
    vettore[0] = n2;
    vettore[1] = n1;
    vettore[2] = n3;
    
    Cartone vet[3] = {{.p= 10,.a= 20,.l= 40}, {.p= 10,.a= 10,.l=  8}, {.p=  9,.a=  3,.l=  5}};
    Cartone vet1[3] = {{.p= 10,.a= 10,.l=  8},{.p= 10,.a= 20,.l= 40}, {.p=  9,.a=  3,.l=  5}};
    
    Cartone c[6] = {{.p= 25,.a= 20,.l= 50}, {.p= 10,.a= 10,.l=  8}, {.p=  9,.a=  3,.l=  5}, {.p=  5,.a= 20,.l=200},{.p= 10,.a= 10,.l=202}, {.p= 24,.a=  3,.l= 55}};
    
    
    TorreCartoni(vet, 3);
    TorreCartoni(vet1, 3);
    TorreCartoni(vettore, 3);
    TorreCartoni(c, 6);
    
    return 0;
}
