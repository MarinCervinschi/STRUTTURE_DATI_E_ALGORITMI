void insertionSort(int arr[], int size) {
    int i, j;
    
    for (i = 1; i < size; i++) {
        j = i;
        while ((j > 0) && (arr[j] < arr[j - 1])) {
            swap(&s[j], &s[j - 1]);
            j--;
        }
    }
}
