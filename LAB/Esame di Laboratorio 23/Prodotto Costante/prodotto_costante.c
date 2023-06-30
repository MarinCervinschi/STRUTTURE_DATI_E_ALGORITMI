#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool try(int n, bool *vccur) {
    int k = 0;
    for (int i = 0; i < n * n; ++i) {
        if (vccur[i]) {
            ++k;
        }
    }
    return k == n;
}

void stampa(int n, const int *vector) {
    printf("[");
    for (int i = 0; i < n * n - 1; ++i) {
        printf("%d, ", vector[i]);
    }
    printf("%d]\n", vector[n * n - 1]);
}

bool verifica2(int n, const int *s, const int *vector) {
    for (int i = 0; i < n * n; ++i) {
        bool found = false;
        for (int j = 0; j < n * n; ++j) {
            if (s[i] == vector[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool verifica1(int n, const int *vector) {
    int *sum = calloc(n, sizeof(int));
    for (int i = 0; i < n; ++i) {
        sum[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i * n; j < (i + 1) * n; ++j) {
            sum[i] *= vector[j];
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        if (sum[i] != sum[i + 1]) {
            free(sum);
            return false;
        }
    }

    free(sum);
    return true;
}

void put(int n, const int *s, int *vector, bool *vccur, int lvl) {
    int j = lvl * n;
    for (int i = 0; i < n * n; ++i) {
        if (vccur[i]) {
            vector[j] = s[i];
            ++j;
        }
    }
}

void RisolviProdottoRec(int n, const int *s, int *vector, bool *vccur, int i, int *count, int *v_best) {
    if (i == n) {
        if (try(n, vccur)) {
            put(n, s, vector, vccur, *count);
            ++*count;
        }
        if (*count == n) {
            if (verifica2(n, s, vector) && verifica1(n, vector)) {
                for (int j = 0; j < n * n; ++j) {
                    v_best[j] = vector[j];
                }
                stampa(n, vector);
                return;
            }
            *count = 0;
        }
        return;
    }

    for (int j = 0; j < n; ++j) {
        for (int h = 0; h < n; ++h) {
            vccur[i + j + h] = true;
            RisolviProdottoRec(n, s, vector, vccur, i + 1, count, v_best);
            vccur[i + j + h] = false;
        }
    }
}

int* RisolviProdotto(int n, const int *s) {
    bool *vccur = calloc(n * n, sizeof(bool));
    int *vector = calloc(n * n, sizeof(int));
    int *v_best = calloc(n * n, sizeof(int));
    int count = 0;
    RisolviProdottoRec(n, s, vector, vccur, 0, &count, v_best);
    free(vccur);
    free(vector);
    return v_best;
}
