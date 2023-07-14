#ifndef domino_h
#define domino_h

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
typedef struct {
    uint8_t val1;
    uint8_t val2;
} Tessera;
typedef struct {
    uint32_t indice;
    bool flipped;
} Placing;

extern Placing *Domino(const Tessera *t, size_t t_size, size_t *ret_size);
#endif /* domino_h */
