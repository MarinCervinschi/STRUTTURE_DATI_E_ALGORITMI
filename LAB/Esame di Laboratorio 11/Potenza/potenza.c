int Potenza(int a, int b){
    if (a == 0 || b == 0) {
        return 1;
    }
    if(b == 1){
        return a;
    }
    return Potenza(a, b-1) * a;
}
