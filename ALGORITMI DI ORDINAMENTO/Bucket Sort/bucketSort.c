#include <stdio.h>
#include <stdlib.h>

// Definizione di una struttura per rappresentare un secchio
typedef struct Bucket {
    int count;
    int* values;
} Bucket;

void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int size, int num_buckets) {
    int i, j;

    // Creazione dell'array di secchi
    Bucket* buckets = (Bucket*)malloc(num_buckets * sizeof(Bucket));

    // Inizializzazione dei secchi
    for (i = 0; i < num_buckets; i++) {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(size * sizeof(int));
    }

    // Inserimento degli elementi nei secchi
    for (i = 0; i < size; i++) {
        int bucket_index = arr[i] / num_buckets;
        buckets[bucket_index].values[buckets[bucket_index].count++] = arr[i];
    }

    // Ordinamento dei secchi e concatenazione dei valori ordinati
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i].values, buckets[i].count);
        for (j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
    }

    // Liberazione della memoria
    for (i = 0; i < num_buckets; i++) {
        free(buckets[i].values);
    }
    free(buckets);
}
