#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern bool TreeIsMirror(const Node *t);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    
    Node *ret = TreeCreateRoot(e + 3,
                               TreeCreateRoot(e + 2, NULL,NULL),
                               TreeCreateRoot(e + 2, NULL,NULL));
    
    
        //       0
        //      / \
        //     /   \
        //    1     1
        //   / \   / \
        //  4   2 2   4
    bool k = true;
    k = TreeIsMirror(ret);
    TreeWriteStdoutPreOrder(ret);
    
    return 0;
}


