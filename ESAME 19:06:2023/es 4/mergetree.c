#include "tree.h"
#include "elemtype.h"
#include <stdio.h>
#include <stdlib.h>
Node *TreeCopy(const Node *t) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
    n->left = TreeCopy(TreeLeft(t));
    n->right = TreeCopy(TreeRight(t));
    return n;
}
Node *MergeTreeRec(const Node *t1, const Node* t2, Node* ret){
    if(t1 == NULL){
        return TreeCopy(t2);
    }
    if(t2 == NULL){
        return TreeCopy(t1);
    }
    const int somma =t1->value + t2->value;
    ret = TreeCreateRoot(&somma, NULL, NULL);
    
    
    ret->left = MergeTreeRec(t1->left, t2->left, ret);
    ret->right = MergeTreeRec(t1->right, t2->right, ret);
    return ret;
}
Node* MergeTree(const Node *t1, const Node* t2){
    if(t1 == NULL && t2 == NULL){
        return NULL;
    }
    if(t1 == NULL){
        return TreeCopy(t2);
    }
    if(t2 == NULL){
        return TreeCopy(t1);
    }
    
    Node *ret = NULL;
    ret = MergeTreeRec(t1, t2, ret);
    
    
    return ret;
}

