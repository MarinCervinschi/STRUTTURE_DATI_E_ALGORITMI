#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool ConfrontVector(int *v1, int *v2, size_t size){
    if(!v1 || !v2){
        return true;
    }
    
    for (size_t i = 0; i != size; ++i){
        if(v1[i] != v2[i]){
            return true;
        }
    }
    return false;
}
int *CreaVector(const int *m,size_t m_size, int *vccur){
    int *vector = calloc(m_size, sizeof(int));
    for (size_t i = 0; i != m_size; ++i){
        for (size_t j = 0; j != m_size; ++j){
            if(vccur[j] == m[i]){
                ++vector[i];
            }
        }
        
    }
    return vector;
}
void Stampa(size_t m_size, int *v){
    for (size_t i = 0; i != m_size; ++i){
        printf("%d ", v[i]);
    }
    printf("\n");
}
void CombinaMoneteRec(int b, const int* m, size_t m_size, int *n_sol, int count, int *vccur, int sum, int **v){
    if(sum == b){
        if(ConfrontVector(*v, CreaVector(m, m_size, vccur), m_size)){
            *v = CreaVector(m, m_size, vccur);
            Stampa(m_size, *v);
            ++(*n_sol);
        }
        return;
    }
    if(sum > b || count == (int)m_size){
        return;
    }

    
    for (size_t i = 0; i != m_size; ++i) {
        vccur[count] = m[i];
        CombinaMoneteRec(b, m, m_size,n_sol, count +1 , vccur, sum+vccur[count], v);
        vccur[count] = 0;
    }
    
    
}
int CombinaMonete(int b, const int* m, size_t m_size){
    
    
    int *vccur = calloc(m_size, sizeof(int));
    int n_sol = 0;
    int *v = NULL;
    CombinaMoneteRec(b, m, m_size, &n_sol, 0, vccur,0, &v);
    
    free(vccur);
    free(v);
    return n_sol;
}
