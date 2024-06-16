#include <string.h>
#include <stdlib.h>
#include <math.h>
int cast(const char str){
    return (int)str;
}
static void AToIRec(const char *str, int *n, int i){
    if(i == (int)strlen(str)){
        return;
    }
    int j = i;
    if(str[0] == '-' && i == 0){
        ++i;
        ++j;
    }
    *n += ((cast(str[i]) - '0') * pow(10, strlen(str)-(j+1)));
    
    AToIRec(str, n, i+1);
}

int AToI(const char *str){
    if (str == NULL) {
        return 0;
    }
    if(strlen(str) == 2 && str[0] == '-'){
        return -(cast(str[1])- '0');
    }else if (strlen(str) == 1){
        return cast(str[0])-'0';
    }
    
    int n = 0;
    
    AToIRec(str, &n, 0);
    
    if(str[0] == '-'){
        return -n;
    }
    return n;
}
