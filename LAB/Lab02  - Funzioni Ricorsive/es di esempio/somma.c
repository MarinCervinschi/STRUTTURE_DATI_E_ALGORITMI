#include "somma.h"
int SommaFinoARec(int n){
    if(n == 1){
        return 1;
    }
    return SommaFinoARec(n - 1) + n;
    
}
int SommaFinoA(int n){
    if (n <= 0) {
        return -1;
    }
    return SommaFinoARec(n);
}


