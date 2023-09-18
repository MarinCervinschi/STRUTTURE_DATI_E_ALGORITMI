#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int Palindromo(int n, int index){
    int num = n %10;
    if(n/10 == 0){
        return num;
    }
    return Palindromo(n/10, index - 1) + pow(10, index) * num;
}
bool IsPalindromo(int n){
    int count = 0, tmp = n;
    while (tmp != 0) {
        tmp /= 10;
        ++count;
    }
    int n1 = Palindromo(n, count -1);
    return n == n1;
}

int main(int argc, const char * argv[]) {
    if (argc != 3) {
        return 1;
    }
    int n = atoi(argv[1]);
    if(n < 0){
        return 1;
    }
    int i = atoi(argv[2]);
   
    for (int j = 0; j < i; ++j) {
        if(IsPalindromo(n)){
            break;
        }
        int count = 0, tmp = n;
        while (tmp != 0) {
            tmp /= 10;
            ++count;
        }
        n  += Palindromo(n, count-1);
    }
    !IsPalindromo(n) ? printf("Lychrel") : printf("Non di Lychrel");
    
    return 0;
}
