// a * b = (a + a) b volte
int ProdottoRec(int a, int b){
    
    if (b == 1) {
        return a;
    }
    return ProdottoRec(a, b-1) + a;
    
}
int ProdottoNegativi(int a, int b){
    if (a == 0 || b == 0) {
        return 0;
    }
    int ret;
    if (b < 0) {
        ret = ProdottoRec(a, -b);
    }else{
        ret = ProdottoRec(a, b);
    }
    if ( b < 0) {
        return -ret;
    }
    return ret;
}
int main(void) {

    int ret;
    ret = ProdottoNegativi(2,-2);

    return 0;
}
