#include <stdio.h>
#include <stdlib.h>

void coatHangerSort(int arr[], int size) {
    int max_num = arr[0];
    int min_num = arr[0];
    int i, j;

    // Trova il valore massimo e minimo nell'array
    for (i = 1; i < size; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
        if (arr[i] < min_num) {
            min_num = arr[i];
        }
    }

    int num_sections = max_num - min_num + 1;
    int* hanger = (int*)calloc(num_sections, sizeof(int));

    // Appendi gli elementi sull'appendiabiti
    for (i = 0; i < size; i++) {
        hanger[arr[i] - min_num]++;
    }

    int index = 0;

    // Sposta gli elementi nell'array in base alla posizione sull'appendiabiti
    for (i = 0; i < num_sections; i++) {
        while (hanger[i] > 0) {
            arr[index++] = i + min_num;
            hanger[i]--;
        }
    }

    free(hanger);
}
