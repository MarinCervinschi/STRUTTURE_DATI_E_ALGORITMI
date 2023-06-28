#include <stdio.h>
#include "prezzo.h"
int main(void) {
    
    struct Articolo vet[] = { {.nome = "pane", .prezzo = 5}, {.nome = "gelato", .prezzo = 3}, {.nome = "pollo", .prezzo = 5} };

    TrovaArticoli(vet, 3, 8);
    
    return 0;
}
