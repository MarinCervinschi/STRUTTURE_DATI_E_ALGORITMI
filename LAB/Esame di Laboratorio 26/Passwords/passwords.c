#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// spampa soluzione corretta

void StampaSol(int n, int *vccur, int nsol){
    for (int j = 0; j != n; ++j) {
        if(j == 0){
            printf("%d) ", nsol);
        }
        if(j + 1 == n){
            printf("%d\n",vccur[j]);
            return;
        }
        printf("%d",vccur[j]);
    }
}

//controlla che la password rispeti le condizioni

bool controlla( int n, int *vccur){
    bool k = true;
    
    // controlla che si sia almeno una coppia
    
    for (int g = 0; g != n-1; ++g) {
        if(vccur[g] == vccur[g+1]){
            k = true;
            break;
        }else{
            k = false;
        }
    }
    // controlla che sia mantenuto l'oridne crescente
    
    if(k){
        for (int g = 0; g != n-1; ++g){
            if(vccur[g] > vccur[g+1]){
                k = false;
                break;
            }
        }
    }
    return k;
}

static void PasswordsRec(int n, int i, bool k, int *vccur, int *nsol){
    
    // caso base
    if(i == n){
        //constrollo le condizioni e stampo
        
        if (controlla(n, vccur)) {
            StampaSol(n, vccur, ++*nsol);
        }
        return;
    }
    // chiamata della funzione di backtracking
    
    for (int j = 0; j != 10; ++j) {
        vccur[i] = j;
        PasswordsRec(n, i+1, k, vccur, nsol);
    }
    
}
void Passwords(int n){
    if( n == 1 || n <= 0){
        return;
    }
    // vettore contenente la password
    
    int *vccur = calloc(n, sizeof(int));
    int nsol = 0;
    PasswordsRec(n, 0, false, vccur, &nsol);
    free(vccur);
}
