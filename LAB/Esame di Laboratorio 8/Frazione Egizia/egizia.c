#include <stdio.h>
void FrazioneEgiziaRec(int n, int d){
    if(d % n == 0){
        int n1 = 1;
        int d1 = d / n;
        if(d%n != 0){
            ++d1;
        }
        printf("%d/%d\n", n1,d1);
        return;
    }
    int n1 = 1;
    int d1 = d / n + 1;
    printf("%d/%d + ", n1,d1);
    
    FrazioneEgiziaRec( ((d*d1)/d * n ) - ((d*d1)/d1 * n1 ), d * d1);
}
void FrazioneEgizia(int n, int d){
    if(n<= 0 || d <= 0 || n >= d){
        printf("Impossibile convertire la frazione data in frazione egizia.\n");
        return;
    }
    FrazioneEgiziaRec(n, d);
}
