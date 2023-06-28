#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
static void BstTreeMinRec(const Node *n, const ElemType **min){
    if (TreeIsLeaf(n) || TreeIsEmpty(n->left)) {
        *min = &n->value;
        return;
    }
    BstTreeMinRec(n->left, min);
}
const ElemType *BstTreeMin(const Node *n){
    if(TreeIsEmpty(n)){
        return NULL;
    }
    const ElemType *min = NULL;
    
    BstTreeMinRec(n, &min);

    return min;
}
static void TreeMinRec(const Node *n, const ElemType **min, int *livello_min, int livello) {
    if (TreeIsEmpty(n)){
        return;
    }

    if ((ElemCompare(TreeGetRootValue(n), *min) < 0) ||
                                                        (ElemCompare(TreeGetRootValue(n), *min) == 0 && livello >= *livello_min)) {
        *min = TreeGetRootValue(n);
        *livello_min = livello;
    }

    TreeMinRec(TreeLeft(n), min, livello_min, livello + 1);
    TreeMinRec(TreeRight(n), min, livello_min, livello + 1);
}

const ElemType *TreeMin(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }
    
    const ElemType *min = TreeGetRootValue(n);
    int livello_min = 0;
    
    TreeMinRec(TreeLeft(n), &min, &livello_min, 1);
    TreeMinRec(TreeRight(n), &min, &livello_min, 1);
    return min;
}
