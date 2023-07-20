#include <stdbool.h>
#include <stdlib.h>

// Funzione per verificare se gli elementi di un sottovettore sono contigui
bool verifica(size_t n, bool *vccur) {
    int num_sott_vet = 0;
    int start = -1;

    // Scorre il vettore di booleani per contare quanti elementi (true) ci sono nel sottovettore e memorizza
    // l'indice del primo elemento (true) trovato
    for (size_t i = 0; i < n; ++i) {
        if (vccur[i]) {
            if (start == -1) {
                start = (int)i;
            }
            ++num_sott_vet;
        }
    }

    // Verifica se gli elementi tra l'indice di start e l'indice di start + num_sott_vet sono contigui
    for (int i = 0; i < num_sott_vet; ++i) {
        if (!vccur[start]) {
            return false; // Gli elementi non sono contigui
        }
        ++start;
    }

    return true; // Gli elementi sono contigui
}

// Funzione ricorsiva per trovare la somma massima di un sottovettore contiguo
void OptimalSubarrayRec(const int *v, size_t n, int count, int *somma_max, int somma, bool *vccur) {
    // Se la somma corrente del sottovettore è maggiore di somma_max e il sottovettore è contiguo, aggiorna somma_max
    if (somma > *somma_max && verifica(n, vccur)) {
        *somma_max = somma;
    }

    // Caso base della ricorsione: tutte le combinazioni possibili sono state esplorate
    if (count == (int)n) {
        return;
    }

    // Includi l'elemento corrente nel sottovettore e passa alla successiva chiamata ricorsiva
    vccur[count] = true;
    OptimalSubarrayRec(v, n, count + 1, somma_max, somma + v[count], vccur);

    // Escludi l'elemento corrente dal sottovettore e passa alla successiva chiamata ricorsiva
    vccur[count] = false;
    OptimalSubarrayRec(v, n, count + 1, somma_max, somma, vccur);
}

// Funzione principale
int OptimalSubarray(const int *v, size_t n) {
    // S e il vettore è vuoto, la somma massima del sottovettore contiguo è 0
    if (n == 0) {
        return 0;
    }

    int somma_max = 0;

    // Vettore di booleani per rappresentare il sottovettore corrente
    bool *vccur = calloc(n, sizeof(bool));

    // Chiama la funzione ricorsiva per calcolare la somma massima di un sottovettore contiguo
    OptimalSubarrayRec(v, n, 0, &somma_max, 0, vccur);

    free(vccur);
    return somma_max;
}
