#include <stdbool.h>
#include <stdlib.h>
#include "elemtype.h"
#include "list.h"
// Funzione per il calcolo della lunghezza di una lista
int ListLength(const Item *i){
    int j = 0;
    while(!ListIsEmpty(i)){
        j++;
        i = ListGetTail(i);
    }
    return j;
}

// Implementazione del bubble sort. Questa funzione effettua
// lo swap degli Item utilizzando il trick del nodo fittizio
// per evitare di gestire separatamente il "caso testa".
Item *BubbleSort(Item *i) {
    Item fake_head = { .next = i };
    
    int dim = ListLength(i);
    bool done = false;

    while(!done) {
        done = true;
        Item *prev = &fake_head;
        Item *curr = prev->next; // Item *curr = ListGetTail(prev);
        for (int j = 0; j < dim && !ListIsEmpty(ListGetTail(curr)); ++j){
            Item *foll = ListGetTail(curr);
            Item *follfoll = ListGetTail(foll);
            if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(foll)) > 0){
                // Devo scambiare i due elementi
                // Al momento abbiamo: prev -> curr -> foll -> follfoll
                // Vogliamo ottenere: prev -> foll -> curr -> follfoll
                prev->next = foll;
                curr->next = follfoll;
                foll->next = curr;
                
                // Aggiorno prev per il prossimo giro (cur Ë gi‡ ok!)
                done = false;
                prev = foll;
            } else {
                // Aggiorno prev e curr per il prossimo giro
                prev = curr;
                curr = foll;
            }
        }
        dim--;
    }

    return fake_head.next;
}
Item *Sort(Item *i) {
   return BubbleSort(i);
}
