#include <stdio.h>
#include <stdlib.h>
int main(int argc,  char * argv[]) {
    if(argc != 3){
        fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: ""mul <a> <b>""");
        return 1;
    }
    
    printf("%i", atoi(argv[1]) * atoi(argv[2]));
    
    return 0;
}
