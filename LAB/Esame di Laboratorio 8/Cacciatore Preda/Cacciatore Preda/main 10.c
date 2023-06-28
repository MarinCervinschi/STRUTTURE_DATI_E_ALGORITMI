#include <stdio.h>
#include <stdlib.h>
extern int* CacciatorePreda(const char *v, size_t v_size, int u);
int NPrede(int *s, int s_size){
    int num =0 ;
    for (int i = 0; i != s_size; ++i) {
        if(s[i] == -2){
            ++num;
        }
    }
    return num;
}
int main(void) {
    
    {
        char v[] = { 'C', 'P', 'P', 'C', 'P'};
        
        for (int i =0 ; i != 5; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 5){
                printf("%c]\n", v[i]);
                continue;
            }
            printf("%c, ", v[i]);
        }
        
        int *s = CacciatorePreda(v, 5, 2);
        int num_prede = NPrede(s, 5);
        for (int i =0 ; i != 5; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 5){
                printf("%d]\nQuesta soluzione permette di catturare %d prede.\n", s[i], num_prede);
                
                continue;
            }
            printf("%d, ", s[i]);
        }
        free(s);
    }
    {
        char v[] = { 'C', 'P', 'C', 'C', 'P', 'P'};
        for (int i =0 ; i != 6; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 6){
                printf("%c]\n", v[i]);
                continue;
            }
            printf("%c, ", v[i]);
        }
        
        int *s = CacciatorePreda(v, 6, 2);
        int num_prede = NPrede(s, 6);
        for (int i =0 ; i != 6; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 6){
                printf("%d]\nQuesta soluzione permette di catturare %d prede.\n", s[i], num_prede);
                
                continue;
            }
            printf("%d, ", s[i]);
        }
        free(s);
    }
    {
        char v[] = { 'c', 'p', 'C', 'P', 'p', 'c'};
        for (int i =0 ; i != 6; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 6){
                printf("%c]\n", v[i]);
                continue;
            }
            printf("%c, ", v[i]);
        }
        
        int *s = CacciatorePreda(v, 6, 3);
        int num_prede = NPrede(s, 6);
        for (int i =0 ; i != 6; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 6){
                printf("%d]\nQuesta soluzione permette di catturare %d prede.\n", s[i], num_prede);
                
                continue;
            }
            printf("%d, ", s[i]);
        }
        free(s);
    }
    {
        char v[] = { 'P', 'P','P'};
        for (int i =0 ; i != 3; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 3){
                printf("%c]\n", v[i]);
                continue;
            }
            printf("%c, ", v[i]);
        }
        
        int *s = CacciatorePreda(v, 3, 1);
        int num_prede = NPrede(s, 3);
        for (int i =0 ; i != 3; ++i) {
            if(i == 0){
                printf("[");
            }
            if(i+1 == 3){
                printf("%d]\nQuesta soluzione permette di catturare %d prede.\n", s[i], num_prede);
                
                continue;
            }
            printf("%d, ", s[i]);
        }
        free(s);
    }
    return 0;
}
