#include <stdio.h>

// Funzione di supporto per lo scambio di due elementi
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funzione di partizionamento per il Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Scegli l'ultimo elemento come pivot
    int i = (low - 1);  // Indice del più piccolo elemento

    for (int j = low; j <= high - 1; j++) {
        // Se l'elemento corrente è più piccolo o uguale al pivot, lo sposta alla sinistra
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Funzione ricorsiva per l'implementazione del Quicksort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Ricorsivamente, ordina le due parti dell'array
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
