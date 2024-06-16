#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
static void IsomorfiRec(const Node *t1, const Node *t2, bool *k, ElemType num1, ElemType num2){
    if(t1 == NULL || t2 == NULL){
        return;
    }
    
    if(ElemCompare(&t1->value, &t2->value) != 0){
        *k = false;
        return;
    }
    
    if ( (( !TreeIsLeaf(t1->left) && TreeIsLeaf(t2->right) ) || ( TreeIsLeaf(t1->left) && !TreeIsLeaf(t2->right) )  ) ) {
        num1 = 1;
        IsomorfiRec(t1->left, t2->left, k, num1, num2);
        
    }else{
        IsomorfiRec(t1->left, t2->right, k, num1, num2);
    }
    if ( (( !TreeIsLeaf(t1->right) && TreeIsLeaf(t2->left) ) || ( TreeIsLeaf(t1->right) && !TreeIsLeaf(t2->left) ) ) ){
        num1 = 1;
        IsomorfiRec(t1->right, t2->right, k, num1, num2);
    }else{
        IsomorfiRec(t1->right, t2->left, k, num1, num2);
        
    }
    
}
bool Isomorfi(const Node *t1, const Node *t2){
    if(t1 == NULL || t2 == NULL){
        return true;
    }
    bool k = true;
    IsomorfiRec(t1, t2, &k, 0, 0);
    return k;
}
