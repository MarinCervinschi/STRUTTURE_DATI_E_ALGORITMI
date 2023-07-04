#include "tree.h"
#include <stdlib.h>
int somma_sottoalbero(Node *t) {
    if (t == NULL) {
        return 0;
    } else {
        int somma_sinistra = somma_sottoalbero(t->left);
        int somma_destra = somma_sottoalbero(t->right);
        int somma_totale = somma_sinistra + somma_destra + t->value;
        return somma_totale;
    }
}

void SostituisciSomma(Node *t) {
    if (t != NULL) {
        int somma_sottoalbero_sinistro = somma_sottoalbero(t->left);
        int somma_sottoalbero_destro = somma_sottoalbero(t->right);
        t->value = somma_sottoalbero_sinistro + somma_sottoalbero_destro + t->value;

        SostituisciSomma(t->left);
        SostituisciSomma(t->right);
    }
}
