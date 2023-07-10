#include <stdio.h>
#include <stdlib.h>

void bookSort(int arr[], int size) {
    int i, j;
    int min_val = arr[0];
    int max_val = arr[0];

    // Trova il valore minimo e massimo nell'array
    for (i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_shelves = max_val - min_val + 1;

    // Crea le sottosezioni (scaffali)
    int** shelves = (int**)malloc(num_shelves * sizeof(int*));
    int* shelf_sizes = (int*)calloc(num_shelves, sizeof(int));

    // Sposta gli elementi nelle sottosezioni corrispondenti
    for (i = 0; i < size; i++) {
        int shelf_index = arr[i] - min_val;
        shelves[shelf_index] = (int*)realloc(shelves[shelf_index], (shelf_sizes[shelf_index] + 1) * sizeof(int));
        shelves[shelf_index][shelf_sizes[shelf_index]] = arr[i];
        shelf_sizes[shelf_index]++;
    }

    // Concatena le sottosezioni ordinate per ottenere l'array ordinato
    int index = 0;
    for (i = 0; i < num_shelves; i++) {
        for (j = 0; j < shelf_sizes[i]; j++) {
            arr[index++] = shelves[i][j];
        }
        free(shelves[i]);
    }

    free(shelves);
    free(shelf_sizes);
}
