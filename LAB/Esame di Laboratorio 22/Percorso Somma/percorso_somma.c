#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>

static void PercorsoSommaRec(Node *t, const ElemType *target, bool *try, ElemType sum){
    if(!t){
        return;
    }
    if(TreeIsLeaf(t)){
        ElemType tmp = sum + t->value;
        if(tmp == *target){
            *try = true;
        }
        return;
    }
    sum += t->value;
    
    if (!*try) {
        PercorsoSommaRec(t->left, target, try, sum);
        PercorsoSommaRec(t->right, target, try, sum);
    }
}
bool PercorsoSomma(Node *t, const ElemType *target){
    if(!t){
        return false;
    }
    
    bool try = false;
    PercorsoSommaRec(t, target, &try, 0);
    
    return try;
    
}
