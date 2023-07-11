#include <stdlib.h>
#include <limits.h>

// Calcola il numero di bambini soddisfatti dato un'assegnazione di biscotti
int BambiniSoddisfatti(const int* bam, size_t bam_size, size_t bis_size, int *vccur) {
    int bamb = 0;
    // Array per tenere traccia dei bambini soddisfatti
    int *sod = calloc(bam_size, sizeof(int));

    for (size_t i = 0; i < bis_size; ++i) {
        int biscotti = vccur[i];
        for (size_t j = 0; j < bam_size; ++j) {
            if (!sod[j]) {
                if (biscotti >= bam[j]) {
                    bamb++;
                    sod[j] = 1;
                } else {
                    // Se i biscotti non sono sufficienti, cerca di assegnare più biscotti dai successivi
                    while (biscotti < bam[j] && i++ < bis_size) {
                        biscotti += vccur[i];
                    }
                    if (biscotti >= bam[j]) {
                        bamb++;
                        sod[j] = 1;
                    }
                }
                break;
            }
        }
    }

    free(sod);
    return bamb;
}

// Funzione ricorsiva per generare tutte le possibili assegnazioni di biscotti
void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int *vccur, int bam_sod, int *bam_sod_max, size_t count) {
    // Calcola il numero di bambini soddisfatti con l'assegnazione corrente
    bam_sod = BambiniSoddisfatti(bam, bam_size, bis_size, vccur);
    if (bam_sod > *bam_sod_max) {
        *bam_sod_max = bam_sod;
    }
    if (count == bis_size) {
        return;
    }

    for (size_t i = count; i < bis_size; ++i) {
        // Prova diverse combinazioni di biscotti per ogni bambino
        vccur[count] = bis[i];
        AssegnaBiscottiRec(bam, bam_size, bis, bis_size, vccur, bam_sod, bam_sod_max, count + 1);
        vccur[i] = 0;
    }
}

// Funzione principale per calcolare il massimo numero di bambini soddisfatti
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
    if (!bam || !bis || bam_size == 0 || bis_size == 0) {
        return 0;
    }

    int bam_sod_max = INT_MIN;
    int *vccur = calloc(bis_size, sizeof(int));

    // Richiama la funzione ricorsiva per generare tutte le possibili assegnazioni di biscotti
    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, vccur, 0, &bam_sod_max, 0);

    free(vccur);
    return bam_sod_max;
}
