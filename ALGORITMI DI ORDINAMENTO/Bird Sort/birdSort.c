#include <stdio.h>

void birdSort(int arr[], int size) {
    int i, j, temp, sorted;

    do {
        sorted = 1;

        for (i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                sorted = 0;
            }
        }
    } while (!sorted);
}
