#include <stdio.h>
#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdbool.h>
//int NumNode(Node *t){
//    if(!t){
//        return 1;
//    }
//    return NumNode(t->left) + NumNode(t->right);
//}
//void PopulatingNextRec(Node *t, Node *tmp, int *i, int num){
//    if (!t || TreeIsLeaf(t)) {
//        ++*i;
//        return;
//    }
//
//    if (TreeIsLeaf(t->left)) {
//        ++*i;
//        t->left->next = t;
//    }
//
//    PopulatingNextRec(t->left, tmp, i, num);
//
//    if(TreeIsLeaf(t->right)){
//        ++*i;
//        t->next = t->right;
//        if(*i != num){
//            t->right->next = tmp;
//        }
//    }else{
//        t->next = t->right->left;
//    }
//    PopulatingNextRec(t->right, tmp, i ,num );
//
//}
//void PopulatingNext(Node *t){
//    if (!t) {
//        return;
//    }
//    int num_node = 0;
//    num_node = NumNode(t) -1 ;
//    int i = 0;
//    PopulatingNextRec(t, t ,&i, num_node);
//}
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
