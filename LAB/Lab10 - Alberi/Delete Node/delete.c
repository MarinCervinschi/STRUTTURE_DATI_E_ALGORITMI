#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
Node *Pred(Node *n) {
    while (!TreeIsEmpty(TreeRight(n))) {
        n = TreeRight(n);
    }
    return n;
}

Node *DeleteBstNodeRec(Node *n, const ElemType *key) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }

    if (ElemCompare(key, &n->value) < 0) {
        n->left = DeleteBstNodeRec(n->left, key);
    } else if (ElemCompare(key, &n->value) > 0) {
        n->right = DeleteBstNodeRec(n->right, key);
    } else {
        // Caso 1: il nodo da eliminare Ë una foglia
        if (TreeIsLeaf(n)) {
            TreeDelete(n);
            return NULL;
        }
        // Caso 2: il nodo da eliminare ha entrambi i figli
        else if (TreeLeft(n) && TreeRight(n)) {

            // Trovo il predecessore
            Node *pred =Pred(TreeLeft(n));

            // Copio il valore del predecessore nel nodo corrente ed
            // elimino il predecessore ricorsivamente. Il predecessore
            // ha al pi˘ il figlio sinistro.
            ElemDelete(&n->value);
            n->value = ElemCopy(&pred->value);
            n->left = DeleteBstNodeRec(n->left, &pred->value);
            return n;
        }
        // Caso 3: il nodo da eliminare ha un solo figlio
        else {
            // Quale?
            
            Node *child = NULL;
            if (TreeLeft(n)) {
                child = n->left;
            } else {
                child = n->right;
            }
            Node *curr = n;

            n = child;

            ElemDelete(&curr->value);
            free(curr);
            return n;
        }
    }
    return n;
}

Node *DeleteBstNode(Node *n, const ElemType *key) {
    return DeleteBstNodeRec(n, key);
}
