#include <stdio.h>
#include "tree.h"
#include "elemtype.h"

#include <stdlib.h>
extern Node* MergeTree(const Node *t1, const Node* t2);
int main(void) {
    
    ElemType v[] = { -2,1,2,3,4,5,6,7,8,9,10, -3, -1};
    
    Node *t1 = TreeCreateRoot(v+0,
                               TreeCreateRoot(v+5,
                                              TreeCreateRoot(v+8, NULL, NULL),
                                              TreeCreateRoot(v+2,   NULL,
                                                             TreeCreateRoot(v+4, NULL, NULL))),
                               TreeCreateRoot(v+1, NULL,
                                              TreeCreateRoot(v+1, NULL, NULL)));
    
    
    Node *t2 = TreeCreateRoot(v+11, TreeCreateRoot(v+10, NULL, NULL),
                              TreeCreateRoot(v+1,
                                             TreeCreateRoot(v+9, NULL, NULL),
                                             TreeCreateRoot(v+ 12, NULL, NULL)));
    
    
    Node *ret = NULL;
    ret = MergeTree(t1, t2);
    
    return 0;
}

