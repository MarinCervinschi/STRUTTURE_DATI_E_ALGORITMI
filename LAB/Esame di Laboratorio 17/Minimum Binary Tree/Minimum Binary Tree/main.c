#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
extern bool Cugini(const Node* t, int a, int b);

int main(void) {
    {
        ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
        
        Node *ret = TreeCreateRoot(e + 6,
                                   TreeCreateRoot(e + 2,
                                                  TreeCreateRoot(e + 3,NULL,NULL),
                                                  TreeCreateRoot(e + 8,NULL,
                                                                 TreeCreateRoot(e + 5, NULL, NULL))),
                                   TreeCreateRoot(e + 9,NULL,
                                                  TreeCreateRoot(e + 4, NULL, NULL)));
        
        

        
        bool k = true;
        k = Cugini(ret, 8, 4);
        k ? printf("true\n") : printf("false\n");
        TreeDelete(ret);
    }
    
    return EXIT_SUCCESS;
}

