#include <stdio.h>

void CocktailSort(int *v, size_t v_size){
    int start = 0;
    int end = (int)v_size - 1;
    int swapped;

    do {
        swapped = 0;

        // Passaggio da sinistra a destra
        for (int i = start; i < end; i++) {
            if (v[i] > v[i + 1]) {
                // Scambia gli elementi adiacenti fuori posizione
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swapped = 1;
            }
        }
        end--;

        // Se non ci sono stati scambi, l'array è già ordinato
        if (!swapped) {
            break;
        }

        // Passaggio da destra a sinistra
        for (int i = end; i > start; i--) {
            if (v[i] < v[i - 1]) {
                // Scambia gli elementi adiacenti fuori posizione
                int temp = v[i];
                v[i] = v[i - 1];
                v[i - 1] = temp;
                swapped = 1;
            }
        }
        start++;
    } while (swapped);
}
