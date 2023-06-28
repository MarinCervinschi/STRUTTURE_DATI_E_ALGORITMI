#include <limits.h>
int DivisioneNegativiRec(int a, int b){
    if (a < 0) {
        return -1;
    }
    if (a == 0) {
        return 0;
    }
    return DivisioneNegativiRec(a-b, b) + 1;
    
}
int DivisioneNegativi(int a, int b){
    if (a == 0) {
        return 0;
    }
    if (b == 0) {
        return INT_MAX;
    }
    if( a < 0 && b < 0){
        return DivisioneNegativiRec(-a, -b);
    }
    if(a < 0){
        return -DivisioneNegativiRec(-a, b);
    }
    if(b< 0){
        return -DivisioneNegativiRec(a, -b);
    }
    
    
    return DivisioneNegativiRec(a, b);
}
int main(void) {

    int ret;
    ret = DivisioneNegativi(9,2);

    return 0;
}
