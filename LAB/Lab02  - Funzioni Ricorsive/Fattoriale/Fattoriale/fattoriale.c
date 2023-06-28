#include <stdio.h>
unsigned long long FattorialeRec(int n){
    
    if (n == 1) {
        return 1;
    }
    return FattorialeRec(n-1) * n;
}
unsigned long long Fattoriale(int n){
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    return  FattorialeRec(n);
}

int main(void) {

    unsigned long long y;
    
    y = Fattoriale(2); // 2
    printf("il fattoriale è:%llu\n", y);
    y = Fattoriale(-2); // 0
    printf("il fattoriale è:%llu\n", y);
    y = Fattoriale(50); // 6
    printf("il fattoriale è:%llu\n", y);
    
    
    return 0;
}
