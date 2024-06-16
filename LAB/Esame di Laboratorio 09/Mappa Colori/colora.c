#include "colora.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Adiacenza(const struct Matrix *m, size_t area1, size_t area2) {
    return m->data[area1 * m->size + area2];
}

bool try(const struct Matrix *m, int *k, int area, int color) {
    for (size_t i = 0; i < m->size; i++) {
        if (Adiacenza(m, area, i) && k[i] == color) {
            return false;
        }
    }
    return true;
}

void MappaColoriRec(const struct Matrix *m, const char *c, size_t c_size, int *sol, int *k, int area) {
    if (area == (int)m->size) {
        for (size_t i = 0; i < m->size; i++) {
            printf("%zu -> %c; ", i, c[k[i]]);
        }
        printf("\n");
        (*sol)++;
        return;
    }

    for (size_t i = 0; i < c_size; i++) {
        if (try(m, k, area, (int)i)) {
            k[area] = (int)i;
            MappaColoriRec(m, c, c_size, sol, k, area + 1);
            k[area] = -1; // Reset color for backtracking
        }
    }
}

int MappaColori(const struct Matrix *m, const char *c, size_t c_size) {
    int sol = 0;
    int *k = calloc(m->size, sizeof(int));
    
    for (size_t i = 0; i < m->size; i++) {
        k[i] = -1;
    }

    MappaColoriRec(m, c, c_size, &sol, k, 0);

    free(k);
    return sol;
}
