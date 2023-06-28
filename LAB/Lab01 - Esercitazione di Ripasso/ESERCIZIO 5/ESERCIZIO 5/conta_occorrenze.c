#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int ContaOccorrenze(const char *filename, const char *str){
    FILE *f = fopen(filename, "r");
    if(!f || str == NULL){
        return 0;
    }
    int c, ret = 0;
    for (int i = 0; (c = fgetc(f)) != EOF; ++i) {
        fseek(f, -1, SEEK_CUR);
        char s[99];
        fscanf(f, "%s", s);
        fprintf(stdout, "%s ", s);
        if(s[0] == str[0]){
            int g = true;
            for (size_t t = 0; t != strlen(str); ++t) {
                if(s[t] != str [t]){
                    g = false;
                    break;
                }
            }
            if(g == false){
                continue;
            }
            ++ret;
        }
    }
    fclose(f);
    return ret;
}
//int main(void) {
//
//    int ret = 0;
//    ret = ContaOccorrenze("file1.txt", "parola");
//    return 0;
//}
