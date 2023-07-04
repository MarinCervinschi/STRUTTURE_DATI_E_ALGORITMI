#include <stdio.h>
#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool k = false;
int leef = 0;
Node *PutTree(Node *n, char *str, size_t i){
    
    if(i >= strlen(str)-1){
        return n;
    }
    if(k){
        i += leef;
    }
    if(ElemCompare(&str[i], ".") == 0){
        k = true;
        ++leef;
        return n = TreeCreateRoot(&str[i+1], NULL, NULL);
    }
    if (ElemCompare(&str[i-1], ".") == 0) {
        leef += 2;
        return n = TreeCreateRoot(&str[i], NULL, NULL);
    }
    n = TreeCreateRoot(&str[i], NULL, NULL);
    k = false;
    
    
    
    n->left = PutTree(n->left, str, i + 1);
    n->right = PutTree(n->right, str, i + 2);
    return n;
}


Node *TreeRead(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        return NULL;
    }
    
    
    char str[255];
    for (int i = 0; fscanf(f, " %c", &str[i]) == 1; ++i){}
        
    
    printf("%s\n", str);
    
    fclose(f);
    Node *ret = PutTree(NULL, str, 0);
    k = false;
    leef = 0;
    return ret;
}
