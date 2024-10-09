#include <stdio.h>

int main() {
    float pendapatan, biayaOperasional, pajak, keuntunganBersih;

    // Meminta input pendapatan total
    printf("Masukkan pendapatan total perusahaan: ");
    scanf("%f", &pendapatan);

    // Meminta input biaya operasional
    printf("Masukkan biaya operasional perusahaan: ");
    scanf("%f", &biayaOperasional);

    // Meminta input pajak
    printf("Masukkan jumlah pajak perusahaan: ");
    scanf("%f", &pajak);

    // Menghitung keuntungan bersih
    keuntunganBersih = pendapatan - (biayaOperasional + pajak);

    // Menampilkan keuntungan bersih
    printf("Keuntungan bersih perusahaan adalah: Rp%.2f\n", keuntunganBersih);

    return 0;
}
