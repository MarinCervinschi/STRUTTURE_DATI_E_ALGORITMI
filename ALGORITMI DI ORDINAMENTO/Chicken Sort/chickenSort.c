#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void chickenSort(int arr[], int size) {
    while (1) {
        int sorted = 1; // Flag per indicare se l'array è completamente ordinato

        for (int i = 0; i < size - 1; i++) {
            int j = rand() % size; // Seleziona casualmente una posizione nell'array

            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                sorted = 0; // L'array non è completamente ordinato
            }
        }

        if (sorted) {
            break; // L'array è completamente ordinato, termina il processo
        }
    }
}
