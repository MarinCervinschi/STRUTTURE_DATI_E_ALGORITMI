// a * b = (a + a) b volte
int ProdottoRec(int a, int b){
    
    if (b == 1) {
        return a;
    }
    return ProdottoRec(a, b-1) + a;
    
}
int Prodotto(int a, int b){
    if (a < 0 || b < 0) {
        return -1;
    }
    if (a == 0 || b == 0) {
        return 0;
    }
    return ProdottoRec(a, b);
}

int main(void) {

    int ret;
    ret = Prodotto(2,-2);

    return 0;
}
