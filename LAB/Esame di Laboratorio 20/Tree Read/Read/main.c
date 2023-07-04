#include <stdio.h>
#include "tree.h"
#include "elemtype.h"
extern Node *TreeRead(const char *filename);
int main(void) {
    
    Node *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7;
    
    tree1 = TreeRead("albero1.txt");
    tree2 = TreeRead("albero2.txt");
    tree3 = TreeRead("albero3.txt");
    tree4 = TreeRead("albero4.txt");
    tree5 = TreeRead("albero5.txt");
    tree6 = TreeRead("albero6.txt");
    tree7 = TreeRead("albero7.txt");
    
    TreeDelete(tree1);
    TreeDelete(tree2);
    TreeDelete(tree3);
    TreeDelete(tree4);
    TreeDelete(tree5);
    TreeDelete(tree6);
    TreeDelete(tree7);
    return 0;
}
