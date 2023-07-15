#include <stdlib.h>
 
#include "tree.h"
extern Node *Tree2Bst(const Node *t);
 
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
            
            Node *tree = TreeCreateRoot(e + 6,
                                       TreeCreateRoot(e + 2,
                                                      TreeCreateRoot(e + 3,NULL,NULL),
                                                      TreeCreateRoot(e + 8,NULL,
                                                                     TreeCreateRoot(e + 5, NULL, NULL))),
                                       TreeCreateRoot(e + 9,NULL,
                                                      TreeCreateRoot(e + 3, NULL, NULL)));
 
    Node *ret;
    ret = Tree2Bst(tree);
    
    TreeDelete(ret);
    TreeDelete(tree);
 
    return EXIT_SUCCESS;
}
