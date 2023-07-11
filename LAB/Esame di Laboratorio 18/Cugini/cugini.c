#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include "elemtype.h"
int Profondità(const Node* t, int x, int lvl){
    int ret = -1;
    if(!t){
        return ret;
    }
    if(t->value == x){
        return lvl;
    }
    ret = Profondità(t->left, x, lvl +1);
    if(ret != -1){
        return ret;
    }
    ret = Profondità(t->right, x, lvl +1);
    return ret;
}
int Padre(const Node* t, int x){
    int ret = -1;
    if(!t){
        return ret;
    }
    if(t->left){
        if(t->left->value == x){
            return t->value;
        }
    }
    if(t->right){
        if(t->right->value == x){
            return t->value;
        }
    }
    ret = Padre(t->left, x);
    if(ret != -1){
        return ret;
    }
    ret = Padre(t->right, x);
    return ret;
}
bool Cugini(const Node* t, int a, int b){
    if(!t){
        return false;
    }
    return (Profondità(t, a, 0) != Profondità(t, b, 0))
            || (Padre(t, a) == Padre(t, b)) ? false : true;
}
