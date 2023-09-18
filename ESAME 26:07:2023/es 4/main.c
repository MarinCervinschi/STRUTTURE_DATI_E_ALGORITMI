#include "elemtype.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
extern bool TreesAreTwins(const Node *t1, const Node *t2);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    {
        Node *t1 = TreeCreateRoot(e + 4,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 1,NULL,NULL),
                                                 TreeCreateRoot(e + 3, NULL, NULL)),
                                  TreeCreateRoot(e + 6,
                                                 TreeCreateRoot(e + 5, NULL, NULL),
                                                 TreeCreateRoot(e + 7, NULL, NULL)));
        Node *t2 = TreeCreateRoot(e + 4,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 1,NULL,NULL),
                                                 TreeCreateRoot(e + 3, NULL, NULL)),
                                  TreeCreateRoot(e + 6,
                                                 TreeCreateRoot(e + 5, NULL, NULL),NULL));
        
   
        printf("%d", TreesAreTwins(t1, t2));
        
        TreeDelete(t1);
        TreeDelete(t2);
        
    }
    
    return EXIT_SUCCESS;
}


