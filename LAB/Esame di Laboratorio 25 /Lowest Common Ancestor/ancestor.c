#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include "elemtype.h"
#include <stdbool.h>
bool TreeContainsNode(const Node* tree, const Node* node){
    bool verifica = false;
   
    if(tree == NULL || node == NULL){
        return verifica;
    }
    if(node->value == tree->value){
        return true;
    }
    if(verifica){
        return true;
    }
    verifica = TreeContainsNode(tree->left, node);
    if(verifica){
        return true;
    }
    verifica = TreeContainsNode(tree->right, node);
    if(verifica){
        return true;
    }
    return verifica;
}
static void Rec(const Node *t, const Node *n1, const Node *n2, const Node **ret){
    if(t == NULL){
        return;
    }
    
    if(TreeContainsNode(t, n1) && TreeContainsNode(t, n2)){
        *ret = t;
    }
    Rec(t->left, n1, n2, ret);
    Rec(t->right, n1, n2, ret);
    
}
const Node* LowestCommonAncestor(const Node *t, const Node *n1, const Node *n2){
    if(n1 == n2){
        return n1;
    }
    if(t == n1){
        return t;
    }
    const Node *ret = NULL;
    
    Rec(t, n1, n2, &ret);
    
    return ret;
}
