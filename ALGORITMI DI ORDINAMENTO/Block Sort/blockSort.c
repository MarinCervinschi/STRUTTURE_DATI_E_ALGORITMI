void insertionSort(int arr[], int size) {
    int i, j;
    int key;

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

void blockSort(int arr[], int size, int block_size) {
    int num_blocks = (size + block_size - 1) / block_size;

    for (int i = 0; i < num_blocks; i++) {
        int left = i * block_size;
        int right = (i + 1) * block_size;

        if (right > size) {
            right = size;
        }

        insertionSort(arr + left, right - left);
    }

    while (num_blocks > 1) {
        for (int i = 0; i < num_blocks - 1; i += 2) {
            int left1 = i * block_size;
            int right1 = (i + 1) * block_size;
            int left2 = (i + 1) * block_size;
            int right2 = (i + 2) * block_size;

            if (right2 > size) {
                right2 = size;
            }

            int* temp = (int*)malloc((right2 - left1) * sizeof(int));

            int k = 0;
            int j1 = left1;
            int j2 = left2;

            while (j1 < right1 && j2 < right2) {
                if (arr[j1] <= arr[j2]) {
                    temp[k++] = arr[j1++];
                } else {
                    temp[k++] = arr[j2++];
                }
            }

            while (j1 < right1) {
                temp[k++] = arr[j1++];
            }

            while (j2 < right2) {
                temp[k++] = arr[j2++];
            }

            for (int j = 0; j < k; j++) {
                arr[left1 + j] = temp[j];
            }

            free(temp);
        }

        num_blocks = (num_blocks + 1) / 2;
    }
}
