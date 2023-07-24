#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
static void StampaLvL(const Node *t, int lvl, int index){
    if(!t){
        return;
    }
    if(index == lvl){
        printf("%d ", t->value);
        return;
    }
    StampaLvL(t->left, lvl, index + 1);
    StampaLvL(t->right, lvl, index + 1);
}
void LevelOrderRec(const Node *t, const Node *tmp, int *is_in, int index){
    if(!t){
        return;
    }
    if(!is_in[index]){
        StampaLvL(tmp, index, 0);
        is_in[index] = 1;
    }
    LevelOrderRec(t->left, tmp, is_in, index + 1);
    LevelOrderRec(t->right, tmp, is_in, index + 1);
}
int ContaLvL(const Node *t){
    if(!t){
        return 0;
    }
    int l = ContaLvL(t->left);
    int r = ContaLvL(t->right);
    return r >= l ? r + 1 : l + 1;
}
void LevelOrder(const Node *t){
    int *is_in = calloc(ContaLvL(t), sizeof(int));
    LevelOrderRec(t, t, is_in, 0);
    free(is_in);
}
