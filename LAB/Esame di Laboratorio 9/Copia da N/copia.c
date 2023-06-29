#include "list.h"
#include "elemtype.h"
#include <stdlib.h>

Item* CopiaDaN(const Item* i, int n) {
    if (i == NULL) {
        return NULL;
    }

    Item *head = NULL;
    Item *tail = NULL;
    int count = 1;

    // Scorrere la lista di input fino all'n-esimo elemento
    while (i != NULL && count != n) {
        i = i->next;
        count++;
    }

    // Se non ci sono abbastanza elementi nella lista di input, restituisci NULL
    if (i == NULL) {
        return NULL;
    }

    // Crea la nuova lista a partire dall'n-esimo elemento
    while (i != NULL) {
        Item *tmp = malloc(sizeof(Item));
        tmp->value = i->value;
        tmp->next = NULL;

        if (head == NULL) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        i = i->next;
    }

    return head;
}
