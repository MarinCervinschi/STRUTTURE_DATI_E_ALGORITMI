int MCD(int m, int n){
    if (n == 0) {
        return m;
    }
    return MCD(n, m%n);
}
