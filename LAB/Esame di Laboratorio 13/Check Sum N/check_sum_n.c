#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
void CheckSumNRec(const Node *t, int n, bool *check, ElemType value){
    if(!t){
        return;
    }
    if(t->value != value && t->value + value == n){
        *check = true;
        return;
    }
    CheckSumNRec(t->left, n, check, value);
    CheckSumNRec(t->right, n, check, value);
}

static void Esplora(const Node *tmp ,const Node *t, int n, bool *check){
    if(!tmp){
        return;
    }
    
    Esplora(tmp->left, t, n, check);
    if(!(*check)){
        CheckSumNRec(t, n, check, tmp->value);
    }else{
        return;
    }
    Esplora(tmp->right, t, n, check);
}
bool CheckSumN(const Node *t, int n){
    bool check = false;
    
    Esplora(t, t, n, &check);
    return check;
}
