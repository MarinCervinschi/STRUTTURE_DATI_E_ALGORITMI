#ifndef STACKS_H
#define STACKS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned *elements;
    size_t m;
} Stack;

typedef struct {
    unsigned somma;
    unsigned *elements;
    size_t m;
}Somma;

extern unsigned MaxSumNStack(Stack *stacks, size_t n);

#endif /* STACKS_H */
