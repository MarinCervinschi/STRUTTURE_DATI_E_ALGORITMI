#include "tree.h"
#include <stdlib.h>
static void InvertOne(Node *t1, Node *t2){
    Node tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
}
static void InvertRec(Node *t){
    if(!t || TreeIsLeaf(t)){
        return;
    }
    if (!t->left) {
        t->left = t->right;
        t->right = NULL;
    }else if (!t->right){
        t->right = t->left;
        t->left = NULL;
    }else{
        InvertOne(t->left, t->right);
    }
    
    InvertRec(t->left);
    InvertRec(t->right);
}
Node* Invert(Node *t){
    if(!t){
        return NULL;
    }
    InvertRec(t);
    return t;
}
