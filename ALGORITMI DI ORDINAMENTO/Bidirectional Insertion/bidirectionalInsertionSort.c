#include <stdio.h>

void bidirectionalInsertionSort(int arr[], int size) {
    int i, j;

    for (i = 1; i < size; i++) {
        int temp = arr[i];

        // Scorri all'indietro per trovare la posizione corretta
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp; // Inserisci l'elemento nella posizione corretta

        // Scorri in avanti per trovare la posizione corretta
        for (j = i + 1; j < size && arr[j] < temp; j++) {
            arr[j - 1] = arr[j];
        }

        arr[j - 1] = temp; // Inserisci l'elemento nella posizione corretta
    }
}
