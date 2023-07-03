#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void Stampa(size_t m_size, int *v){
    for (size_t i = 0; i != m_size; ++i){
        printf("%d ", v[i]);
    }
    printf("\n");
}
void CombinaMoneteRec(int b, const int* m, size_t m_size, int *n_sol, int sum, int *v, size_t start_index){
    if(sum == b){
        Stampa(m_size, v);
        ++(*n_sol);
        return;
    }
    if(sum > b){
        return;
    }
    for (size_t i = start_index; i < m_size ; ++i) {
            ++v[i];
            CombinaMoneteRec(b, m, m_size, n_sol, sum + m[i], v, i);
            --v[i];
            
        }
    
}
int CombinaMonete(int b, const int* m, size_t m_size){
    int n_sol = 0;
    int *v = calloc(m_size, sizeof(int));
    CombinaMoneteRec(b, m, m_size, &n_sol, 0, v,0);
    free(v);
    return n_sol;
}
