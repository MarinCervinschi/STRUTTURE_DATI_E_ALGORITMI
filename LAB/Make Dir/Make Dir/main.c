#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    char *directoryPath = "/Users/marin/Documents/STRUTTURE DATI E ALGORITMI/ALGORITMI DI ORDINAMENTO/";
    char *directoryName = calloc(25, sizeof(char));
    FILE *f = fopen("data.txt", "r");
    char *path = calloc(100, sizeof(char));
    while (fscanf(f, "%[^\n]", directoryName) == 1) {
        directoryName = realloc(directoryName, strlen(directoryName) * sizeof(char));
        snprintf(path, 100, "%s%s", directoryPath, directoryName);
        path = realloc(path, strlen(path)* sizeof(char));
        mkdir(path, 0777);
        fseek(f, 1, SEEK_CUR);
    }
    
    free(directoryName);
    free(path);
    fclose(f);
    return 0;
}
