#include <stdio.h>
#define MAX_ITEMS 100

typedef struct {
    char nama[30];
    int harga;
} MenuItem;

void tampilkanMenu(MenuItem makanan[], int jumlahMakanan, MenuItem minuman[], int jumlahMinuman) {
    printf("Menu Makanan:\n");
    for (int i = 0; i < jumlahMakanan; i++) {
        printf("%d. %s - Rp %d\n", i + 1, makanan[i].nama, makanan[i].harga);
    }
    
    printf("\nMenu Minuman:\n");
    for (int i = 0; i < jumlahMinuman; i++) {
        printf("%d. %s - Rp %d\n", i + 1, minuman[i].nama, minuman[i].harga);
    }
}

int hitungTotal(int makananPesanan[], int jumlahMakanan, int minumanPesanan[], int jumlahMinuman, MenuItem makanan[], MenuItem minuman[]) {
    int total = 0;
    for (int i = 0; i < jumlahMakanan; i++) {
        if (makananPesanan[i] > 0) {
            total += makanan[i].harga * makananPesanan[i];
        }
    }
    for (int i = 0; i < jumlahMinuman; i++) {
        if (minumanPesanan[i] > 0) {
            total += minuman[i].harga * minumanPesanan[i];
        }
    }
    return total;
}

int main() {
    MenuItem makanan[] = {
        {"Nasi Goreng", 20000},
        {"Mie Goreng", 15000},
        {"Ayam Penyet", 25000}
    };
    MenuItem minuman[] = {
        {"Teh", 5000},
        {"Kopi", 10000},
        {"Air Mineral", 3000}
    };

    int jumlahMakanan = sizeof(makanan) / sizeof(makanan[0]);
    int jumlahMinuman = sizeof(minuman) / sizeof(minuman[0]);
    
    int makananPesanan[MAX_ITEMS] = {0};
    int minumanPesanan[MAX_ITEMS] = {0};
    int pilihan, jumlah;

    printf("Selamat datang di Program Pemesanan Makanan\n");

    tampilkanMenu(makanan, jumlahMakanan, minuman, jumlahMinuman);

    printf("\nSilahkan pilih makanan (1-%d) dan jumlah: ", jumlahMakanan);
    while (1) {
        printf("\nPilihan (0 untuk selesai): ");
        scanf("%d", &pilihan);
        if (pilihan == 0) break;

        printf("Jumlah: ");
        scanf("%d", &jumlah);
        if (pilihan > 0 && pilihan <= jumlahMakanan) {
            makananPesanan[pilihan - 1] += jumlah;
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    printf("\nSilahkan pilih minuman (1-%d) dan jumlah: ", jumlahMinuman);
    while (1) {
        printf("\nPilihan (0 untuk selesai): ");
        scanf("%d", &pilihan);
        if (pilihan == 0) break;

        printf("Jumlah: ");
        scanf("%d", &jumlah);
        if (pilihan > 0 && pilihan <= jumlahMinuman) {
            minumanPesanan[pilihan - 1] += jumlah;
        } else {
            printf("Pilihan tidak valid!\n");
        }
    }

    int total = hitungTotal(makananPesanan, jumlahMakanan, minumanPesanan, jumlahMinuman, makanan, minuman);
    printf("\nTotal Pesanan Anda: Rp %d\n", total);
    
    return 0;
}
