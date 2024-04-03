#include "no_cycle.h"
#include <stdbool.h>
#include <string.h>

void RemoveCycle(Item* head) {
    if (head == NULL) {
        return;
    }

    Item *slow = head, *fast = head;

    // Trova l'incontro tra slow e fast
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    // Se non c'è ciclo, ritorna
    if (fast == NULL || fast->next == NULL) {
        return;
    }

    // Trova l'inizio del ciclo
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Trova l'ultimo nodo del ciclo e rimuovi il ciclo
    while (fast->next != slow) {
        fast = fast->next;
    }
    fast->next = NULL;
}
