#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern double Mediano(const Node *t);
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
        
   
        printf("mediano = %f\n", Mediano(t1));
        
        TreeDelete(t1);
        
    }
    {
        Node *t1 = TreeCreateRoot(e + 7,
                                  TreeCreateRoot(e + 4,
                                                 TreeCreateRoot(e + 2,
                                                                TreeCreateRoot(e + 1, NULL, NULL),NULL),
                                                 TreeCreateRoot(e + 5, NULL, NULL)),
                                  TreeCreateRoot(e + 8,NULL,NULL));
        
   
        printf("mediano = %f\n", Mediano(t1));
        
        TreeDelete(t1);
        
    }
    
    return EXIT_SUCCESS;
}


