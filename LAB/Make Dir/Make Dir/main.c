#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main(void) {
    char *directoryPath = "/Users/marin/Documents/STRUTTURE DATI E ALGORITMI/ALGORITMI DI ORDINAMENTO/";
    char *directoryName = calloc(50, sizeof(char));
    FILE *f = fopen("data.txt", "r");
    char *path = calloc(200, sizeof(char));
    while (fscanf(f, "%[^\n]", directoryName) == 1) {
        directoryName = realloc(directoryName, strlen(directoryName) * sizeof(char));
        snprintf(path, 200, "%s%s", directoryPath, directoryName);
        //strcat(path, "/Complessità.txt");
        path = realloc(path, strlen(path)* sizeof(char));
        FILE *k = fopen(path, "w");
        fclose(k);
        mkdir(path, 0777);
        fseek(f, 1, SEEK_CUR);
    }
    
    free(directoryName);
    free(path);
    fclose(f);
    return 0;
}
