#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ParoleT9Rec(size_t size, int *numeri, const char *lettere[], char *vccur, int *n_sol, size_t count){
    if(count == size){
        printf("%s\n", vccur);
        ++(*n_sol);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if(i == numeri[count]){
            for (size_t j = 0; j < strlen(lettere[i]); ++j) {
                vccur[count] = lettere[i][j];
                ParoleT9Rec(size, numeri, lettere, vccur, n_sol, count + 1);
            }
        }
    }
}
int ParoleT9(const char *str){
    if(!str){
        return 0;
    }
    int n_sol = 0;
    
    const char *lettere[] = { NULL, NULL, "ABC" , "DEF", "GHI", "JKL", "MNO" , "PQRS", "TUV", "WXYZ"};
    int *numeri = calloc(strlen(str), sizeof(int));
    int num = atoi(str);
    for (size_t i =strlen(str)-1; i != (size_t)-1; --i) {
        numeri[i] = num % 10;
        num /= 10;
    }
    char *vccur = calloc(strlen(str)+1, sizeof(char));
    
    ParoleT9Rec(strlen(str), numeri, lettere, vccur, &n_sol, 0);
    
    free(numeri);
    free(vccur);
    return n_sol;
}
