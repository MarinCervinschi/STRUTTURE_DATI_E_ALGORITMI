#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
#include "tree.h"

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
        
        
       
        
        TreeDelete(t1);
    }
    
    
    return EXIT_SUCCESS;
}


