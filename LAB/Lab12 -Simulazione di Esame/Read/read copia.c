#include <stdio.h>
#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdbool.h>
Node *TreeReadRec(FILE *f) {
    ElemType c;
    if (fscanf(f, " %c", &c) != 1) {
        return TreeCreateEmpty();
    }
    
    if (c == '.') {
        // Ho trovato una foglia, devo leggerne il valore
        fscanf(f, " %c", &c);
        return TreeCreateRoot(&c, TreeCreateEmpty(), TreeCreateEmpty());
    }

    Node * l = TreeReadRec(f);
    Node * r = TreeReadRec(f);
    //return TreeCreateRoot(&c, TreeReadRec(f), TreeReadRec(f));
    return TreeCreateRoot(&c, l, r);
}

Node *TreeRead(const char *filename) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        return TreeCreateEmpty();
    }

    Node * t = TreeReadRec(f);

    fclose(f);
    return t;
}
