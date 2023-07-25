void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        // Trova l'indice dell'elemento più piccolo nell'array non ancora ordinato
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Scambia l'elemento più piccolo con l'elemento nella posizione corrente
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}
