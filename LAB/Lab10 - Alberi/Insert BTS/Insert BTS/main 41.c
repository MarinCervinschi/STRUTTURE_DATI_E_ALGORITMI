#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern Node *BstInsert(const ElemType *e, Node *n);
extern Node *BstInsertRec(const ElemType *e, Node *n);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    
    Node *ret = TreeCreateRoot(e + 4,
                               TreeCreateRoot(e + 3,
                                TreeCreateRoot(e + 1,
                                 TreeCreateRoot(e + 1, NULL, NULL),
                                 TreeCreateRoot(e + 2, NULL, NULL)), NULL),
                               TreeCreateRoot(e + 7,
                                TreeCreateRoot(e + 5, NULL, NULL),
                                TreeCreateRoot(e + 8, NULL, NULL)));
    
    
    const ElemType k = 6;
    ret = BstInsert(&k, ret);
    TreeWriteStdoutPreOrder(ret);
    
    return 0;
}


