#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern const Node* LowestCommonAncestor(const Node *t, const Node *n1, const Node *n2);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    {
        Node *t1 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 4,NULL,NULL),
                                                 TreeCreateRoot(e + 5, NULL,NULL)),
                                  TreeCreateRoot(e + 3,
                                                 TreeCreateRoot(e + 6, NULL,
                                                                TreeCreateRoot(e + 8, NULL, NULL)),
                                                 TreeCreateRoot(e + 7, NULL, NULL)));
        
        
       
        

        printf("%d", LowestCommonAncestor(t1, t1->left->left, t1->left->right)->value);
        TreeDelete(t1);
    }
    
    
    return EXIT_SUCCESS;
}


