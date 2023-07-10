#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdbool.h>

static void TreeIsMirrorRec(Node *t1,Node *t2, bool *k){
    if( (!t1) || (!t2) ){
        return;
    }
    if( (t1->left && !t2->right) || (!t1->left && t2->right) ||
                        (t1->right && !t2->left) || (!t1->right && t2->left) ){
        *k = false;
        return;
    }
    if(t1->value != t2->value){
        *k = false;
        return;
    }
    TreeIsMirrorRec(t1->left, t2->right, k);
    TreeIsMirrorRec(t1->right, t2->left, k);
}
bool TreeIsMirror(Node *t){
    if(!t || TreeIsLeaf(t)){
        return true;
    }
    bool k = true;
    TreeIsMirrorRec(t->left, t->right, &k);
    return k;
}
