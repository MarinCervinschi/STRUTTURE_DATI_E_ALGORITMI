#include <stdio.h>

void insertionSort(int arr[], int size) {
    int i, j, key;

    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        // Sposta gli elementi maggiori di key dietro di una posizione
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Inserisci la chiave nella sua posizione corretta
        arr[j + 1] = key;
    }
}
