#include "tree.h"
#include <stdlib.h>
#include <float.h>

void MedianoRec(const Node *t, int index_mediano, int *index, double *mediano){
    if(!t){
        return;
    }
    
    MedianoRec(t->left, index_mediano, index, mediano);
    
    ++*index;
    
    if(index_mediano == *index){
        *mediano += t->value;
    }
    
    MedianoRec(t->right, index_mediano, index, mediano);
}

int CountNode(const Node *t){
    if(!t){
        return 0;
    }
    return CountNode(t->left) + CountNode(t->right) + 1;
}
double Mediano(const Node *t){
    if(!t){
        return DBL_MAX;
    }
    double mediano = 0;
    int nodi = CountNode(t);
    int index = 0;
    if(nodi % 2 == 0){
        MedianoRec(t, nodi / 2, &index, &mediano);
        index = 0;
        MedianoRec(t, nodi / 2 +1, &index, &mediano);
        mediano /= 2;
    }else{
        MedianoRec(t, nodi / 2 +1, &index, &mediano);
    }
    
    return mediano;
}
