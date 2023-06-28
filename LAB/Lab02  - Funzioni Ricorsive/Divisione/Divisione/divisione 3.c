int DivisioneRec(int a, int b){
    if (a < 0) {
        return -1;
    }
    if (a == 0) {
        return 0;
    }
    return DivisioneRec(a-b, b) + 1;
    
}
int Divisione(int a, int b){
    if (a == 0) {
        return 0;
    }
    if (a < 0 || b< 0 || b == 0) {
        return -1;
    }
    if (a < b) {
        return 0;
    }
    
    return DivisioneRec(a, b);
}
int main(void) {

    int ret;
    ret = Divisione(13,3);

    return 0;
}
