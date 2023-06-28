int Minimo(const int *v, int v_size){
    
    if (v_size == 1) {
        return v[0];
    } else{
        int minimo = Minimo(v, v_size -1);
        if (v[v_size - 1] < minimo) {
            return v[v_size - 1];
        }
        else{
            return minimo;
        }
    }
}

int main(void) {
    int v[] = { 1, 2, 5,};
    int Min;
    Min = Minimo(v, 3);
    
    return 0;
}
