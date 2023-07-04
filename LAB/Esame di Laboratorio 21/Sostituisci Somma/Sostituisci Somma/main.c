#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
extern void SostituisciSomma(Node *t);
Node* createNode(ElemType value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* buildTree(void) {
    Node* root = createNode(0);

    root->left = createNode(1);
    root->right = createNode(1);

    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    root->left->left->left = createNode(5);
    root->left->left->right = createNode(6);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(8);
    
    root->right->left->left = createNode(8);
    root->right->left->right = createNode(7);
    root->right->right->left = createNode(6);
    root->right->right->right = createNode(5);

    root->left->left->right->left = createNode(9);
    root->right->right->left->right = createNode(9);

    return root;
}
int main(void) {
    {
        ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
        
        Node *ret = TreeCreateRoot(e + 2,
                                   TreeCreateRoot(e + 1,
                                                  TreeCreateRoot(e + 7,NULL,NULL),
                                                  TreeCreateRoot(e + 4,NULL, NULL)),
                                   TreeCreateRoot(e + 3,
                                                  TreeCreateRoot(e + 2, NULL, NULL),
                                                  TreeCreateRoot(e + 4, NULL, NULL)));
        Node* root = buildTree();
        
        SostituisciSomma(root);
        TreeDelete(ret);
    }
    
    return EXIT_SUCCESS;
}

