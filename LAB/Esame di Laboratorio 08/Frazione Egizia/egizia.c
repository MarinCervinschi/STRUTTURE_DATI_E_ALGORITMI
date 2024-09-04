#include <stdio.h>

void FrazioneEgiziaRec(int n, int d) {
    if (n == 0) return;  // Caso base: se il numeratore è 0, non c'è nulla da fare.

    if (d % n == 0) {
        printf("1/%d\n", d / n);  // Se n divide esattamente d, stampa l'ultima frazione.
        return;
    }

    int d1 = d / n + 1;  // Trova il più piccolo denominatore d1 tale che 1/d1 < n/d.
    printf("1/%d + ", d1);

    // Chiamata ricorsiva con la nuova frazione da convertire.
    FrazioneEgiziaRec(n * d1 - d, d * d1);
}

void FrazioneEgizia(int n, int d) {
    if (n <= 0 || d <= 0 || n >= d) {
        printf("Impossibile convertire la frazione data in frazione egizia.\n");
        return;
    }
    FrazioneEgiziaRec(n, d);
}
