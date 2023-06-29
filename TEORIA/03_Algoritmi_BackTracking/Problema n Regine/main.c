#include <stdio.h>
#define DIM 8

void visualizza(int *colonna, int nsol){
    printf("\nSoluzione numero: %d\n", nsol);
    for (int k = 0; k < DIM; k++) {
        for (int i = 0; i < DIM; i++) {
            if(i == colonna[k]){
                printf("1 ");
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void verifica(int j, int *riga, int *colonna, int *diag1, int *diag2, int *nsol, int *ntent, int *ncall){
//    char invio;
    for (int i = 0; i < DIM; i++) {
        (*ntent)++;
        if((riga[i] == 0) && (diag1[i+j] == 0) && (diag2[i-j+7] == 0)){
            //regina nella casella i,j
            colonna[j] = i;
            //riga i sotto scacco
            riga[i] = 1;
            //diagonale secondaria i+j sotto scacco
            diag1[i+j] = 1;
            //diagonale secondaria i-j+7 sotto scacco
            diag2[i-j+7] = 1;
            if(j < DIM - 1){
                (*ncall)++;
                verifica(j+1, riga, colonna, diag1, diag2, nsol, ntent, ncall);
            }
            else{ //trovata 1 soluzione
                (*nsol)++;
                visualizza(colonna, *nsol);
//                scanf("%c", &invio);
                
            }
            //libero le righe e le diagonali esaminate
            riga[i] = 0;
            diag1[i+j] = 0;
            diag2[i-j+7] = 0;
        }
    }
}

int main(void){
    
    int riga[DIM];
    int diag1[2 * DIM - 1];
    int diag2[2 * DIM - 1];
    int colonna[DIM];
    int sol = 0, num = 0, chiama = 0;
    
    for (int i = 0; i < DIM; i++) {
        riga[i]=0;
    }
    for (int i = 0; i < (DIM * 2) - 1; i++) {
        diag1[i]=0;
        diag2[i]=0;
    }
    
    verifica(0, riga, colonna, diag1, diag2, &sol, &num, &chiama);
    
    printf("\nNumero totale soluzioni = %d, su %d tentativi, %d chiamate", sol, num, chiama);
    
    return 0;
}

