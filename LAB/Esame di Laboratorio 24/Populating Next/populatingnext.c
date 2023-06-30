#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
Node* LeftMost(Node* t) {
    while (!TreeIsEmpty(TreeLeft(t))) {
        t = TreeLeft(t);
    }
    return t;
}
Node* PopulatingNextRec(Node* t, Node* father, bool right) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    if (TreeIsLeaf(t)) {
        if (!right) {
            t->next = father;
            return NULL;
        }
        return t;
    }
    Node* l = PopulatingNextRec(t->left, t, false);
    if (l != NULL) {
        l->next = t;
    }
    t->next = LeftMost(t->right);
    Node* r = PopulatingNextRec(t->right, t, true);
    if (TreeIsEmpty(t->right)) {
        return t;
    }
    return r;
}
void PopulatingNext(Node* t) {
    if (TreeIsEmpty(t)) {
        return;
    }
    PopulatingNextRec(t, NULL, false);
}
