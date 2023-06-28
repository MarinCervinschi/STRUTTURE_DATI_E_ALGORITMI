#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
static void LevelSumeRec(const Node *t, size_t level, int i, int *sum){
    if(TreeIsEmpty(t)){
        return;
    }
    if(i == (int)level){
        *sum += t->value;
        return;
    }
    
    LevelSumeRec(t->left, level, i+1, sum);
    LevelSumeRec(t->right, level, i+1, sum);
    
}
int LevelSum(const Node *t, size_t level){
    if(TreeIsEmpty(t)){
        return 0;
    }
    if (TreeIsLeaf(t)) {
        return t->value;
    }
    int sum = 0;
    
    LevelSumeRec(t, level, 0, &sum);
    
    return sum;
}
