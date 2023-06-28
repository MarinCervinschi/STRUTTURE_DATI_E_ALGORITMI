#include "elemtype.h"
#include "tree.h"
#define COUNT 10
void PrintTreeStdoutRec(const Node *t, int space){
    if(TreeIsEmpty(t)){
        return;
    }
    
    space += COUNT;
    
    PrintTreeStdoutRec(t->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++){
        printf(" ");
    }
    printf("%d\n", t->value);
    
    PrintTreeStdoutRec(t->left, space);
}
void PrintTreeStdout(const Node *t){
    PrintTreeStdoutRec(t, 0);
    
}

