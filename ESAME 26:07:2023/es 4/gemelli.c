#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
static void Esplora(const Node *t1, const Node *t2, bool *gemelli){
    if(!t1 && !t2){
        return;
    }
    
    if((t1 && !t2) || (!t1 && t2)){
        *gemelli = false;
        return;
    }
    
    Esplora(t1->left, t2->left, gemelli);
    Esplora(t1->right, t2->right, gemelli);
}
bool TreesAreTwins(const Node *t1, const Node *t2){
    if(!t1 || !t2){
        return true;
    }
    
    bool gemelli = true;
    Esplora(t1, t2, &gemelli);
    return gemelli;
}
