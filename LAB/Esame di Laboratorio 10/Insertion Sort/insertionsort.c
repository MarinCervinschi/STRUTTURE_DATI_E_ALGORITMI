#include <stdlib.h> // for size_t
void InsertionSort(int *v, size_t v_size){
    if (!v || v_size < 2) {
        return;
    }
    int j = 0, key = 0;
    
    for (size_t i = 1; i < v_size; i++) {
        key = v[i];
        j = (int)i - 1;
        
        // Sposta gli elementi maggiori di key dietro di una posizione
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        // Inserisci la chiave nella sua posizione corretta
        v[j + 1] = key;
    }
}

