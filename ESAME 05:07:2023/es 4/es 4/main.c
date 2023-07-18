#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
extern const Node* BiggestColoredTree(const Node *t);
int main(void) {
    
    Node *ret = TreeCreateRoot("r",
                               TreeCreateRoot("b",
                                              TreeCreateRoot("b",NULL,NULL),
                                              TreeCreateRoot("b",
                                                             TreeCreateRoot("v", NULL, NULL), NULL)),
                               TreeCreateRoot("v",
                                              TreeCreateRoot("b", NULL, NULL),NULL));
    
    
    const Node *t;
    t = BiggestColoredTree(ret);
    
    return EXIT_SUCCESS;
}

