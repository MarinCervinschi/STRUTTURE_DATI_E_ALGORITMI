#include <stdio.h>
int main(void) {
    FILE *f = fopen("data.txt", "rw");
    char name[25];
    int i = 1;
    FILE *ret = fopen("Algoritmi di Odrinamento.txt", "w");
    while (fscanf(f, "%[^\n]", name) == 1) {
        fprintf(ret, "%d) %s;\n", i++,name);
        fseek(f, 1, SEEK_CUR);
    }
    fclose(f);
    fclose(ret);
    return 0;
}
