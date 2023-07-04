#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void PasswordRec(const char *str, int n, int *n_sol, char *vccur, int count){
    if(count == n){
        printf("%s\n", vccur);
        ++(*n_sol);
        return;
    }
    
    for (size_t i = 0; i != strlen(str); ++i){
        vccur[count] = str[i];
        PasswordRec(str, n, n_sol, vccur, count+1);
    }
    
}
int Password(const char *str, int n){
    if(!str){
        return 0;
    }
    int n_sol = 0;
    char *vccur = calloc(n, sizeof(char));
    
    PasswordRec(str, n, &n_sol, vccur, 0);
    
    free(vccur);
    return n_sol;
}
