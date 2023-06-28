#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void ToUpper(char *str){
    if(!str){
        return;
    }
    //for (int i = 0; str[i] != 0; ++i)
    for (int i = 0; *(str + i) != 0; ++i) {
        //if(str[i] >= 'a' && str[i] <= 'z')
        if(*(str + i) >= 'a' && *(str + i) <= 'z'){
            //str[i] = str[i] - ('a' - 'A');
            *(str + i) = *(str + i) - ('a' - 'A');
        }
    }
    
}
int main(void) {
   
    char str[] = "Prova";
    ToUpper(str);
    return 0;
}
