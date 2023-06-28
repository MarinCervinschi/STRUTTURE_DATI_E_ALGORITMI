#include <stdio.h>
#include <stdlib.h>
void StampaVector(int *vector, int vector_size){
    for (int i = 0; i != vector_size; ++i) {
        if(i == 0){
            printf("[");
        }
        if(i+1 == vector_size){
            printf("%d]\n", vector[i]);
            continue;
        }
        printf("%d, ", vector[i]);
    }
}
extern void Stooge(int *vector, size_t vector_size);

int main(void) {
    
    int vet[] = { 3, 5, 1, 6, 2, 7, 4, 9};
    StampaVector(vet, 8);
    Stooge(vet, 8);
    StampaVector(vet, 8);

    return 0;
}
