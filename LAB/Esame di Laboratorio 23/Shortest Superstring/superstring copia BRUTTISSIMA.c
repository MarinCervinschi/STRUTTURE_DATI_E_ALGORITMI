#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Verifica se tutti i valori in un array booleano sono true
bool verifica(bool *v, size_t n) {
    for (size_t i = 0; i != n; ++i) {
        if (!v[i]) {
            return false;
        }
    }
    return true;
}

// Funzione per calcolare l'overlap tra due stringhe e restituire la stringa risultante
char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;

    // Verifica se strShort è una sottostringa di strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }

    int maxOverlap = 0;
    bool longGoesFirst = true;

    // Prova a mettere strShort alla fine di strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }

    // Prova a mettere strLong alla fine di strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }

    char* res = malloc(lenLong + lenShort - maxOverlap + 1);

    // Costruzione della stringa risultante in base all'overlap massimo trovato
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }

    *overlapping = maxOverlap;
    return res;
}
bool k = false;
void BackTrack(const char **v, size_t v_size, bool *vccur, size_t i, char **res, int* overlapping, int *ovr_max, bool **is_in, bool **best, size_t n) {
    if (i == n) {
        size_t lvl[n];
        for (size_t j = 0, h = 0; j != v_size; ++j) {
            if (vccur[j]) {
                lvl[h] = j;
                ++h;
            }
        }
        if(n == 2){
            Overlap(v[lvl[0]], v[lvl[1]], overlapping);
            if (*overlapping >= *ovr_max) {
                *res = Overlap(v[lvl[0]], v[lvl[1]], overlapping);
                for (size_t j = 0; j != v_size; ++j) {
                    is_in[0][j] = vccur[j];
                }
                *ovr_max = *overlapping;
            }
        }else{
            Overlap(*res, v[lvl[0]], overlapping);
            if (*overlapping >= *ovr_max) {
                *res = Overlap(*res, v[lvl[0]], overlapping);
                for (size_t j = 0; j != v_size; ++j) {
                    is_in[0][j] = vccur[j];
                }
                *ovr_max = *overlapping;
            }
        }
        return;
    }
    
    for (size_t j = 0; j != v_size; ++j) {
        if (!vccur[j]) {
            if (!best[0][j]) {
                vccur[j] = true;
                BackTrack(v, v_size, vccur, i+1, res, overlapping, ovr_max, is_in, best, n);
                vccur[j] = false;
            }
        }
    }
}

char* SolveSuperstring(const char **v, size_t v_size) {
    if (v == NULL || v_size < 1) {
            return NULL;
        }
    char *res = calloc(255, sizeof(char));
    bool *vccur = calloc(v_size, sizeof(bool));
    int over = 0, over_max = 0;
    bool *is_in = calloc(v_size, sizeof(bool));
    bool *best = calloc(v_size, sizeof(bool));
    size_t l = 0;
    BackTrack(v, v_size, vccur, 0, &res, &over, &over_max, &is_in, &best, 2);
    over = 0;
    over_max = 0;
    ++l;
    for (size_t j = 0; j != v_size; ++j) {
        if (!best[j]) {
            best[j] = is_in[j];
        }
    }
    while (!verifica(best, v_size) && l < v_size) {
        BackTrack(v, v_size, vccur, 0, &res, &over, &over_max, &is_in, &best, 1);
        over = 0;
        over_max = 0;
        ++l;
        for (size_t j = 0; j != v_size; ++j) {
            if (!best[j]) {
                best[j] = is_in[j];
            }
        }
    }
 
    res = realloc(res, (strlen(res) + 1) * sizeof(char));

    free(vccur);
    free(is_in);
    free(best);
    return res;
}
