#include <stdio.h>
#include <stdlib.h>

void beadSort(int arr[], int size) {
    int i, j;
    int max_num = arr[0];

    // Trova il valore massimo nell'array
    for (i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Crea una corda con grani inizializzati a 0
    int* rope = (int*)calloc(max_num, sizeof(int));

    // Posiziona i grani sulla corda
    for (i = 0; i < size; i++) {
        for (j = 0; j < arr[i]; j++) {
            rope[j]++;
        }
    }

    // Riempie l'array con i numeri raccolti dalla corda
    int index = 0;
    for (i = 0; i < max_num; i++) {
        while (rope[i] > 0) {
            arr[index++] = i + 1;
            rope[i]--;
        }
    }

    free(rope);
}
