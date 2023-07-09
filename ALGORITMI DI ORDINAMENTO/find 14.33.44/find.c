#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
bool Find(char *nome, const char *filename){
    FILE *f = fopen(filename, "r");
    char *nome2 = calloc(25, sizeof(char));
    while (fscanf(f, "%[^\n]", nome2) == 1) {
        nome2 = realloc(nome2, strlen(nome2) * sizeof(char));
        if(strcmp(nome, nome2) == 0){
            fclose(f);
            return true;
        }
        fseek(f, 1, SEEK_CUR);
    }
    free(nome2);
    fclose(f);
    return false;
}
int main(int argc, const char * argv[]) {
    char nome[25];
    for (size_t i = 1; i != argc; ++i) {
        strcat(nome, argv[i]);
        if(i+1 != argc){
            strcat(nome, " ");
        }
    }
    Find(nome, "data.txt") ? printf("true") : printf("false");
    return 0;
}
