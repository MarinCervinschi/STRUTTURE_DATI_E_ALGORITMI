#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool verifica(int n, char *vccur){
    if(vccur[0] == ')' || vccur[n*2-1] == '('){
        return false;
    }
    int count = 0;
    bool *k = calloc(n*2, sizeof(bool));
    for (int i = 0; i != n*2-1; ++i) {
        if(vccur[i] == '('){
            for (int j = i+1; j != n*2; ++j){
                if(vccur[j] == ')' && !k[j]){
                    k[j] = true;
                    ++count;
                    break;
                }
            }
        }
    }
    if(count != n){
        free(k);
        return false;
    }else {
        free(k);
        return true;
    }
}
void Stampa(int n, char *vccur){
    for (int i = 0; i != n*2; ++i) {
        printf("%c", vccur[i]);
    }
    printf("\n");
}
static void ParentesiRec(int n, int count, int *n_sol, char *vccur){
    
    if(count == n*2){
        if(verifica(n, vccur)){
            Stampa(n,vccur);
            ++(*n_sol);
        }
        
        return;
    }
    
    vccur[count] = '(';
    ParentesiRec(n, count + 1, n_sol, vccur);
    vccur[count] = ')';
    ParentesiRec(n, count + 1, n_sol, vccur);
}

int Parentesi(int n){
    if(n < 0){
        return -1;
    }
    if(n == 0){
        return 0;
    }
    
    char *vccur = calloc(n*2, sizeof(char));
    int n_sol = 0;
    ParentesiRec(n, 0, &n_sol, vccur);
    
    free(vccur);
    return n_sol;
        
}
