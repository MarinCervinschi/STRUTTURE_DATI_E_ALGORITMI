#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
} Card;

void cardSort(int arr[], int size) {
    Card* deck = (Card*)malloc(size * sizeof(Card));

    // Crea un mazzo di carte
    for (int i = 0; i < size; i++) {
        deck[i].value = arr[i];
    }

    // Ordina le carte utilizzando l'algoritmo di Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (deck[j].value > deck[j + 1].value) {
                // Scambia le carte
                Card temp = deck[j];
                deck[j] = deck[j + 1];
                deck[j + 1] = temp;
            }
        }
    }

    // Estrai gli elementi ordinati dal mazzo
    for (int i = 0; i < size; i++) {
        arr[i] = deck[i].value;
    }

    free(deck);
}
