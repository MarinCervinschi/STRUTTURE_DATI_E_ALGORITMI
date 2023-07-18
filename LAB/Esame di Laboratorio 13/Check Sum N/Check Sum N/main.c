#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
extern bool CheckSumN(const Node *t, int n);

int main(void) {
    {
        ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
        
        Node *ret = TreeCreateRoot(e + 7,
                                   TreeCreateRoot(e + 6,
                                                  TreeCreateRoot(e + 2,
                                                                 TreeCreateRoot(e + 1, NULL, NULL),NULL),
                                                  TreeCreateRoot(e + 5,NULL,NULL)),
                                   TreeCreateRoot(e + 8,NULL,NULL));
        
        
        printf("%d\n", CheckSumN(ret, 7));
        TreeDelete(ret);
    }
    
    return EXIT_SUCCESS;
}

