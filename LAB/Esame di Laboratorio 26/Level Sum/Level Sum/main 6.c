#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern int LevelSum(const Node *t, size_t level);
int main(void) {
    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
    {
        Node *t1 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 4,
                                                                TreeCreateRoot(e + 7, NULL, NULL),
                                                                TreeCreateRoot(e + 8, NULL, NULL)),
                                                 TreeCreateRoot(e + 5, NULL, NULL)),
                                  TreeCreateRoot(e + 3,
                                                 TreeCreateRoot(e + 6, NULL, NULL),NULL));
        
        
        int ret = 0, level = 2;
        ret = LevelSum(t1, level);
        printf("La somma di LevelSum(t1, %d) è : %d\n", level, ret);
        
        
        TreeDelete(t1);
        
    }
    {
        Node *t3 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,NULL, NULL),
                                  TreeCreateRoot(e + 3,NULL,NULL));
        
        int ret = 0, level = 2;
        ret = LevelSum(t3, level);
        printf("La somma di LevelSum(t1, %d) è : %d\n", level, ret);
        
        
        
        TreeDelete(t3);
        
    }
    
    return EXIT_SUCCESS;
}


