#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
Node *BstInsert(const ElemType *e, Node *n){
    if(TreeIsEmpty(n)){
        return TreeCreateRoot(e, NULL, NULL);
    }
    Node *tmp = n;
    
    while (!TreeIsEmpty(n)) {
        if(ElemCompare(e, TreeGetRootValue(n)) <= 0){
            
            if(TreeIsEmpty(TreeLeft(n))){
                n->left = TreeCreateRoot(e, NULL, NULL);
                break;
            }
            n = TreeLeft(n);
        }
        else{
            
            if(TreeIsEmpty(TreeRight(n))){
                n->right = TreeCreateRoot(e, NULL, NULL);
                break;
            }
            n = TreeRight(n);
        }
    }
    
    return tmp;
}
Node *BstInsertRec(const ElemType *e, Node *n){
    if(TreeIsEmpty(n)){
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }
    if(ElemCompare(e, TreeGetRootValue(n)) <= 0){
        n->left = BstInsertRec(e, TreeLeft(n));
    }
    else{
        n->right = BstInsertRec(e, TreeRight(n));
    }
    return n;
}
