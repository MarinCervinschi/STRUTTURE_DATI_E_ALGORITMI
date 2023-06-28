#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
void CountDominantRec(const Node *t, ElemType *num){
    if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
        return;
    }
    ElemType valore = 0;
    if(t->left == NULL){
        valore = TreeRight(t)->value;
    }
    else if (t->right == NULL){
        valore = TreeLeft(t)->value;
    }
    else{
        valore = TreeLeft(t)->value + TreeRight(t)->value;
    }
    if(ElemCompare(TreeGetRootValue(t), &valore) > 0){
        ++(*num);
    }
    
    CountDominantRec(t->left, num);
    CountDominantRec(t->right, num);
    return ;
}

int CountDominant(const Node *t){
    if(TreeIsEmpty(t)){
        return 0;
    }
    ElemType num = 0;
    CountDominantRec(t, &num);
    return num;
}
