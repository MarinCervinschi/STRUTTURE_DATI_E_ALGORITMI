#include "tree.h"
#include <stdlib.h>
int NumNode(Node *t){
    if (!t) {
        return 0;
    }
    int ret = NumNode(t->left) + 1;
    ret = NumNode(t->left) + 1;
    return ret;
}
void SostituisciSommaRec(Node *t, int alt, int lvl){
    if (!t || TreeIsLeaf(t)) {
        return;
    }

    if(t->left && t->right){
        if(TreeIsLeaf(t->left) && TreeIsLeaf(t->right)){
            t->value += t->left->value + t->right->value;
        }
    }
    if(t->left && !t->right){
        t->value += t->left->value ;
    }
    if(!t->left && t->right){
        t->value += t->right->value;
    }
    SostituisciSommaRec(t->left, alt-1, lvl+1);
    SostituisciSommaRec(t->right, alt-1, lvl+1);

    if(  ( t->left && t->right ) && lvl <= alt){
        if(!TreeIsLeaf(t->left) || !TreeIsLeaf(t->right)){
            t->value += t->left->value + t->right->value;
        }
    }
}
void SostituisciSomma(Node *t){
    int alt = NumNode(t);
    SostituisciSommaRec(t, alt,0);
}
