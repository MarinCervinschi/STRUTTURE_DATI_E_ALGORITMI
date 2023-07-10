#include <stdio.h>
#include <stdlib.h>

void binSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int min_val = arr[0];
    int max_val = arr[0];

    // Trova il valore minimo e massimo nell'array
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int num_bins = max_val - min_val + 1;
    int* bins = (int*)calloc(num_bins, sizeof(int));

    // Conta il numero di elementi in ogni secchio
    for (int i = 0; i < size; i++) {
        bins[arr[i] - min_val]++;
    }

    int index = 0;

    // Riempie l'array con gli elementi dai secchi
    for (int i = 0; i < num_bins; i++) {
        while (bins[i] > 0) {
            arr[index++] = i + min_val;
            bins[i]--;
        }
    }

    free(bins);
}
