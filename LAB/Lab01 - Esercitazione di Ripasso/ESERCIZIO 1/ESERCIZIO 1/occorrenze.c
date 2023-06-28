#include <stdio.h>
#include <string.h>

int main(int argc,  char * argv[]) {
    if(argc != 3){
        fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: ""occorrenze <s> <c>""");
        return 1;
    }
    int g = 0;
    
    for (size_t i = 0; i != strlen(argv[1]); ++i) {
        if(argv[1][i] == *argv[2]){
            ++g;
        }
    }
    printf("%i", g);
    
    return 0;
}
