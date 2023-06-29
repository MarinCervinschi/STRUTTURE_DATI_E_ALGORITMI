#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern Node *DeleteBstNode(Node *n, const ElemType *key);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    
    Node *ret = TreeCreateRoot(e + 12,
                               TreeCreateRoot(e + 4,
                                TreeCreateRoot(e + 0,
                                 TreeCreateRoot(e + 11, NULL, NULL),
                                 TreeCreateRoot(e + 8, NULL, NULL)),
                                TreeCreateRoot(e + 2,
                                 TreeCreateRoot(e + 1, NULL, NULL), NULL)),
                               TreeCreateRoot(e + 21,
                                TreeCreateRoot(e + 5, NULL, NULL),
                                TreeCreateRoot(e + 18, NULL, NULL)));
    
    //                    12
    //                   / \
    //                  /   \
    //                 4     21
    //                / \   / \
    //               /   \ 5   18
    //              /     \
    //             0       2
    //            /  \    / \
    //          11    8 1
    

    printf("prima:\n");
    TreeWriteStdoutPreOrder(ret);
    const ElemType key = 4;
    ret = DeleteBstNode(ret, &key);
    
    printf("dopo:\n");
    TreeWriteStdoutPreOrder(ret);
    TreeDelete(ret);
    return 0;
}


