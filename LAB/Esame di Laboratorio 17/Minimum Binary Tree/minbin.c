#include "tree.h"
#include <stdlib.h>
Node *CreateMinBinTree(const ElemType *v, size_t v_size){
    if(!v || v_size == 0){
        return NULL;
    }
    // Trova l'indice dell'elemento minimo nel vettore v
    size_t min_index = 0;
    for (size_t i = 1; i < v_size; i++) {
        if (v[i] < v[min_index]) {
            min_index = i;
        }
    }
    
    Node *root = TreeCreateRoot(&v[min_index], NULL, NULL);
    
    // Costruisci ricorsivamente il sottoalbero sinistro
    root->left = CreateMinBinTree(v, min_index);

    // Costruisci ricorsivamente il sottoalbero destro
    root->right = CreateMinBinTree(v + min_index + 1, v_size - min_index - 1);

    return root;
}
