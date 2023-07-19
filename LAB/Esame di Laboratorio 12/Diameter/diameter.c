#include <stdlib.h>
#include "tree.h"
// Funzione per calcolare la massima tra due interi
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Funzione ricorsiva per calcolare l'altezza di un sottoalbero
int Height(const Node *root) {
    if (!root){
        return 0;
    }

    int left_height = Height(root->left);
    int right_height = Height(root->right);

    return 1 + max(left_height, right_height);
}

// Funzione ricorsiva per calcolare il diametro di un albero binario
int Diameter(const Node *root) {
    if (!root){
        return 0;
    }

    // Calcoliamo le altezze dei sottoalberi sinistro e destro
    int left_height = Height(root->left);
    int right_height = Height(root->right);

    // Calcoliamo il diametro del sottoalbero sinistro e destro
    int left_diameter = Diameter(root->left);
    int right_diameter = Diameter(root->right);

    // Il diametro dell'albero è il massimo tra il diametro del figlio sinistro,
    // il diametro del figlio destro e il percorso più lungo tra due foglie che
    // passa attraverso la radice.
    return max(max(left_diameter, right_diameter), left_height + right_height)+1;
}
