#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Verifica se una strada è illuminata correttamente da un insieme di lampadine
bool VerificaStradaIlluminata(const int *light, bool *vccur, size_t size, int M, int R) {
    int luce = 0;
    for (size_t i = 0; i < size; ++i) {
        if (vccur[i]) {
            // Se la distanza tra luce[i] e la luce precedente supera R, la strada non è illuminata correttamente
            if (light[i] - R > luce) {
                return false;
            }
            // Aggiorna la variabile luce con la posizione dell'ultima lampadina illuminata
            luce = light[i] + R;
        }
    }
    // Controlla se l'ultima luce è sufficiente per illuminare la strada fino a M
    return luce >= M;
}

// Verifica se una soluzione contiene lampadine sovrapposte (soluzione non valida)
bool VerificaSoluzioneValida(bool *ret, size_t size) {
    for (size_t i = 0; i != size; ++i) {
        if (ret[i]) {
            return false; // Soluzione non valida se ci sono lampadine sovrapposte
        }
    }
    return true; // Soluzione valida se non ci sono lampadine sovrapposte
}

// Funzione ricorsiva per trovare la combinazione ottimale di lampadine che illuminano la strada
void OptimalIlluminationRec(int M, int R, const int *light, size_t light_size, bool **ret, bool *vccur, int count, int *lampadine) {
    // Se la strada è correttamente illuminata, aggiorna il numero minimo di lampadine necessarie
    if (VerificaStradaIlluminata(light, vccur, light_size, M, R)) {
        int lampadine_tmp = *lampadine;
        *lampadine = 0;
        for (size_t i = 0; i != light_size; ++i) {
            if (vccur[i]) {
                ++*lampadine;
            }
        }
        // Se il numero di lampadine attualmente necessario è minore del numero minimo registrato, aggiorna la soluzione
        if (*lampadine < lampadine_tmp) {
            for (size_t i = 0; i != light_size; ++i) {
                ret[0][i] = vccur[i];
            }
        }
    }

    // Caso base della ricorsione: tutte le combinazioni possibili sono state esplorate
    if (count == (int)light_size) {
        return;
    }

    // Prova ad aggiungere o meno la lampadina corrente alla combinazione e continua la ricorsione
    for (size_t i = count; i != light_size; ++i) {
        vccur[i] = true; // Aggiungi la lampadina corrente
        OptimalIlluminationRec(M, R, light, light_size, ret, vccur, count + 1, lampadine);
        vccur[i] = false; // Non aggiungere la lampadina corrente
    }
}

// Funzione principale per trovare la combinazione ottimale di lampadine che illuminano la strada
bool* OptimalIllumination(int M, int R, const int *light, size_t light_size) {
    // Gestione dei casi speciali: se il vettore di luce è vuoto o NULL, restituisci NULL
    if (!light || light_size == 0) {
        return NULL;
    }

    bool *ret = calloc(light_size, sizeof(bool)); // Vettore per memorizzare la combinazione ottimale
    bool *vccur = calloc(light_size, sizeof(bool)); // Vettore per rappresentare la combinazione corrente
    int lampadine = INT_MAX; // Numero minimo di lampadine necessarie

    // Chiama la funzione ricorsiva per trovare la combinazione ottimale
    OptimalIlluminationRec(M, R, light, light_size, &ret, vccur, 0, &lampadine);

    // Se la soluzione ottenuta ha lampadine sovrapposte, libera la memoria e restituisci NULL
    if (VerificaSoluzioneValida(ret, light_size)) {
        free(ret);
        free(vccur);
        return NULL;
    }

    free(vccur);
    return ret; // Restituisci la combinazione ottimale
}
