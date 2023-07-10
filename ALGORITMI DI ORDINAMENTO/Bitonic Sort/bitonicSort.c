#include <stdio.h>
#include <stdlib.h>

void exchange(int* a, int* b, int dir) {
    if ((dir && (*a > *b)) || (!dir && (*a < *b))) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void bitonicMerge(int arr[], int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;
        for (int i = low; i < low + k; i++) {
            exchange(&arr[i], &arr[i + k], dir);
        }
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void bitonicSort(int arr[], int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;
        bitonicSort(arr, low, k, 1);
        bitonicSort(arr, low + k, k, 0);
        bitonicMerge(arr, low, count, dir);
    }
}
