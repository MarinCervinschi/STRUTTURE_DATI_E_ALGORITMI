#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static void ReverseRec(const char *str, int index, char *ret, size_t len){
    if(str[index] == 0){
        return;
    }
    ret[index] = str[len];
    ReverseRec(str, index+1, ret, len-1);
    
}
char* ReverseString(const char* str){
    char *ret = calloc(strlen(str) + 1, sizeof(char));
    ReverseRec(str, 0, ret, strlen(str)-1);
    
    return ret;
}
