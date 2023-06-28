#include <stdio.h>
#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern void PrintTreeStdout(const Node *t);
extern bool Equivalenti(const Node *t1, const Node *t2);
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
        
        
        
        
        
        Node *t2 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 4,
                                                                TreeCreateRoot(e + 21, NULL, NULL),
                                                                TreeCreateRoot(e + 2, NULL, NULL)),
                                                 TreeCreateRoot(e + 5, NULL, NULL)),
                                  TreeCreateRoot(e + 3,
                                                 TreeCreateRoot(e + 12, NULL, NULL), NULL));
        
        bool k = true;
        k = Equivalenti(t1, t2);
        
        if(k){
            printf("Gli alberi t1 e t2 sono equivalenti\n");
        }else{
            printf("Gli alberi t1 e t2 NON sono equivalenti\n");
        }
        
        TreeDelete(t1);
        TreeDelete(t2);
        
    }
    {
        Node *t3 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 4,NULL,NULL),
                                                 TreeCreateRoot(e + 5, NULL, NULL)),
                                  TreeCreateRoot(e + 5,NULL,NULL));
        
        
        Node *t4 = TreeCreateRoot(e + 1,
                                  TreeCreateRoot(e + 2,
                                                 TreeCreateRoot(e + 4,
                                                                TreeCreateRoot(e + 3, NULL, NULL),NULL),
                                                 TreeCreateRoot(e + 5, NULL, NULL)),
                                  TreeCreateRoot(e + 5,NULL,NULL));
        
        
        bool k = true;
        k = Equivalenti(t3, t4);
        
        if(k){
            printf("Gli alberi t3 e t4 sono equivalenti\n");
        }else{
            printf("Gli alberi t3 e t3 NON sono equivalenti\n");
        }
        
        TreeDelete(t3);
        TreeDelete(t4);
        
    }
    
    return EXIT_SUCCESS;
}


