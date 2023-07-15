#include <stdlib.h>
#include "tree.h"
Node *Tree2BstRec(const ElemType *e, Node *root){
    if(!root){
        return TreeCreateRoot(e, NULL, NULL);
    }
    if(ElemCompare(e, &root->value) <= 0){
        root->left = Tree2BstRec(e, root->left);
    }else{
        root->right = Tree2BstRec(e, root->right);
    }
    return root;
}
static void Esplora(const Node *t, Node **root){
    if(!t){
        return;
    }
    
    Esplora(t->left, root);
    
    *root = Tree2BstRec(&t->value, *root);
    
    Esplora(t->right, root);
}
Node *Tree2Bst(const Node *t){
    if(!t){
        return NULL;
    }
    Node *root = NULL;
    Esplora(t, &root);
    return root;
}
