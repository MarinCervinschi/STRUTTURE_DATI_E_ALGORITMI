#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>

bool IsMult(const Node *t1, const Node *t2){
    if(t1->value % t2->value == 0){
        return true;
    }else{
        return false;
    }
}

static void EquivalentiRec(const Node *t1, const Node *t2, bool *k){
    if(TreeIsEmpty(t1) && TreeIsEmpty(t2)){
        return;
    }
    if(TreeIsLeaf(t1) && TreeIsLeaf(t2)){
        if (t1 == NULL || t2 == NULL) {
            *k =false;
            return;
        }
        if(ElemCompare(&t1->value, &t2->value) > 0){
            if(IsMult(t1, t2)){
                return;
            }
        }else if(ElemCompare(&t1->value, &t2->value) < 0){
            if(IsMult(t2, t1)){
                return;
            }
        }else{
            return;
        }
    }
    
    if(ElemCompare(&t1->value, &t2->value) != 0){
        *k =false;
        return;
    }
    
    EquivalentiRec(t1->left, t2->left, k);
    EquivalentiRec(t1->right, t2->right, k);
    
}
bool Equivalenti(const Node *t1, const Node *t2){
    bool k = true;
    EquivalentiRec(t1, t2, &k);
    return k;
}
