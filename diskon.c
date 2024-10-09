#include <stdio.h>
//Akhdan Arden Sabian
//2211102141
float hitungDiskon(float totalBelanja) {
    float diskon;


    if (totalBelanja > 1000000) {
        diskon = 0.20;
    } else if (totalBelanja >= 500000) {
        diskon = 0.10;
    } else {
        diskon = 0.0;
    }

    return diskon;
}

int main() {
    float totalBelanja, diskon, totalSetelahDiskon;


    printf("Masukkan total belanja Anda (dalam Rp): ");
    scanf("%f", &totalBelanja);


    diskon = hitungDiskon(totalBelanja);
    

    totalSetelahDiskon = totalBelanja - (totalBelanja * diskon);


    printf("Diskon yang didapat: %.2f%%\n", diskon * 100);
    printf("Total yang harus dibayar setelah diskon: Rp %.2f\n", totalSetelahDiskon);

    return 0;
}
