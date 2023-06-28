#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
const Node *TreeIsMirrorRec(const Node *t){
    if(TreeIsEmpty(t) || TreeIsLeaf(t)){
        return t;
    }
    if (TreeIsEmpty(t->left) || TreeIsEmpty(t->right)) {
        return t;
    }
    if(TreeIsLeaf(t->left) || TreeIsLeaf(t->right)){
        ElemSwap(&t->left->value, &t->right->value);
    }
    
    TreeIsMirrorRec(t->left);
    TreeIsMirrorRec(t->right);
    return t;
}
bool TreeCmp(const Node *t1, const Node *t2){
    while (!TreeIsEmpty(t1)) {
        if ( (t1->left && !t1->right) || (t2->left && !t2->right) ) {
            return false;
        }
        if(ElemCompare(&t1->value, &t2->value) != 0){
            return false;
        }
        t1 = t1->left;
        t2 = t2->left;
    }
    return true;
}
bool TreeIsMirror(const Node *t){
    if(TreeIsEmpty(t) || TreeIsLeaf(t)){
        return true;
    }
    const Node *tmp = t;
    tmp = TreeIsMirrorRec(t->right);
    
    return TreeCmp(t->left, tmp);
}
