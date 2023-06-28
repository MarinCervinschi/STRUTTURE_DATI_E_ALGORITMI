#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
static void BstTreeMaxRec(const Node *n, const ElemType **max){
    if (TreeIsLeaf(n) || TreeIsEmpty(n->right)) {
        *max = &n->value;
        return;
    }
    if(n->right->value == n->value){
        *max = &n->value;
        return;
    }
    BstTreeMaxRec(n->right, max);
}
const ElemType *BstTreeMax(const Node *n){
    if(TreeIsEmpty(n)){
        return NULL;
    }
    const ElemType *max = NULL;
    
    BstTreeMaxRec(n, &max);

    return max;
}
static void TreeMaxRec(const Node *n, const ElemType **max, int *livello_max, int livello) {
    if (TreeIsEmpty(n)){
        return;
    }

    if ((ElemCompare(TreeGetRootValue(n), *max) > 0) ||
                                                        (ElemCompare(TreeGetRootValue(n), *max) == 0 && livello < *livello_max)) {
        *max = TreeGetRootValue(n);
        *livello_max = livello;
    }

    TreeMaxRec(TreeLeft(n), max, livello_max, livello + 1);
    TreeMaxRec(TreeRight(n), max, livello_max, livello + 1);
}

const ElemType *TreeMax(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }
    
    const ElemType *max = TreeGetRootValue(n);
    int livello_max = 0;
    
    TreeMaxRec(TreeLeft(n), &max, &livello_max, 1);
    TreeMaxRec(TreeRight(n), &max, &livello_max, 1);
    return max;
}
