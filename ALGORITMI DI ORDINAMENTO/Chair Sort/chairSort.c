#include <stdio.h>
#include <stdlib.h>

void chairSort(int arr[], int size) {
    int max_num = arr[0];
    int i, j;

    // Trova il valore massimo nell'array
    for (i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    // Crea un array di sedie
    int* chairs = (int*)calloc(max_num + 1, sizeof(int));

    // Posiziona gli elementi sulle sedie
    for (i = 0; i < size; i++) {
        chairs[arr[i]]++;
    }

    // Riempie l'array con gli elementi raccolti dalle sedie
    int index = 0;
    for (i = 0; i <= max_num; i++) {
        for (j = 0; j < chairs[i]; j++) {
            arr[index++] = i;
        }
    }

    free(chairs);
}
