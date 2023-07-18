#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <string.h>

void ContaNodi(const Node *t, ElemType colore,int *sum){
    if(!t){
        return;
    }
    if(ElemCompare(&colore, &t->value) == 0){
        *sum += 1;
    }else{
        *sum = 0;
        return;
    }
    ContaNodi(t->left, colore, sum);
    ContaNodi(t->right , colore, sum);
}

void BiggestColoredTreeRec(const Node *t,  const Node **ret, int *nodi_max, int nodi){
    if(!t){
        return;
    }
    nodi = 0;
    ContaNodi(t, t->value, &nodi);
    if(*nodi_max < nodi){
        *nodi_max = nodi;
        *ret = t;
    }
    
    
    BiggestColoredTreeRec(t->left, ret, nodi_max, nodi);
    BiggestColoredTreeRec(t->right, ret, nodi_max, nodi);
}
const Node* BiggestColoredTree(const Node *t){
    if(!t){
        return NULL;
    }
    
    int nodi_max= 0;
    
    const Node *ret = NULL;
    BiggestColoredTreeRec(t, &ret, &nodi_max, 0);

    
    return ret;
}
