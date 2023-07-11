#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
extern Node *CreateMinBinTree(const ElemType *v, size_t v_size);

int main(void) {
    {
        const ElemType v[] = { 3,2,1,6,8,5 };
        Node *ret;
        ret = CreateMinBinTree(v, 6);
        TreeDelete(ret);
    }
    
    return EXIT_SUCCESS;
}

