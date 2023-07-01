#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
extern Node* Invert(Node *t);
int main(void) {
    
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    
    Node *ret = TreeCreateRoot(e + 2,
                               TreeCreateRoot(e + 1,
                                              TreeCreateRoot(e + 7,NULL,NULL),NULL),
                               TreeCreateRoot(e + 3,
                                              TreeCreateRoot(e + 2, NULL, NULL),
                                              TreeCreateRoot(e + 4, NULL, NULL)));
    
    
    ret = Invert(ret);
    
    return EXIT_SUCCESS;
}

