#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void bandSort(int arr[], int size, int num_bands) {
    if (size <= 1) {
        return;
    }

    int band_size = (size + num_bands - 1) / num_bands;
    int* temp = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < num_bands; i++) {
        int left = i * band_size;
        int right = (i + 1) * band_size;

        if (right > size) {
            right = size;
        }

        int band_length = right - left;
        int* band = arr + left;

        // Ordina la banda utilizzando il Merge Sort
        if (band_length > 1) {
            bandSort(band, band_length, num_bands);
        }
    }

    // Unisce le bande ordinate
    for (int i = 0; i < num_bands - 1; i++) {
        int left = i * band_size;
        int right = (i + 1) * band_size;

        if (right > size) {
            right = size;
        }

        int band_length = right - left;
        int* band = arr + left;

        merge(temp, temp, band, i * band_size, band_length);
    }

    // Copia l'array temporaneo nell'array originale
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}
