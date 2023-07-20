#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
static void Rec(const char *str, size_t index, size_t len, bool *palin){
    if(index == strlen(str)){
        return;
    }
    if(str[index] != str[len]){
        *palin = false;
        return;
    }
    Rec(str, index+1, len-1, palin);
}
bool IsPalindromo(const char* str){
    if (str == NULL) {
        return false;
    }
    if(!str){
        return true;
    }
    
    bool Palin = true;
    Rec(str, 0, strlen(str) -1, &Palin);
    return Palin;
}
