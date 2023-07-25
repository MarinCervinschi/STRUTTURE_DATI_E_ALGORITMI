#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int verifica(const char *r, int n, int *v_curr){
    int ret = 0;
    for (int i = 0; i < n-1; ++i) {
        if(r[i] == 'i' || r[i] == 'I'){
            ret = v_curr[i] < v_curr[i + 1] ? 1 : 0;
            
        }else{
            ret = v_curr[i] > v_curr[i + 1] ? 1 : 0;
        }
        if(ret == 0){
            break;
        }
    }
    return ret;
}
int Is_in(int n, int *v_curr, int value){
    for (int i = 0; i < n; ++i) {
        if(v_curr[i] == value){
            return 1;
        }
    }
    return 0;
}
static void RegoleRec(const char *r, int n, int *v_curr, int count){
    if(count == n && verifica(r, n, v_curr)){
        for (int i = 0; i < n; ++i) {
            printf("%d ", v_curr[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i < n+1; ++i) {
        if(!Is_in(n, v_curr, i)){
            v_curr[count] = i;
            RegoleRec(r, n, v_curr, count + 1);
            v_curr[count] = 0;
        }
    }
}
void Regole(const char *r){
    if(!r){
        return;
    }
    if(r[0] == 0){
        printf("1");
        return;
    }
    int n = (int)strlen(r) + 1;
    int *v_curr = calloc(n, sizeof(int));
    
    RegoleRec(r, n, v_curr, 0);
    
    free(v_curr);
}
