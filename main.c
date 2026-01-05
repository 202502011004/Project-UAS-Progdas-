#include <stdio.h>
#include <stdio.h>


int main() {

    // ===== DATA =====
    char film[3][40] = {
        "Spider-Man: Into the Spider-Verse",
        "Frozen II",
        "Toy Story"
    };

    char jadwal[3][2][10] = {
        {"13.00", "16.30"},
        {"14.00", "18.00"},
        {"15.30", "19.00"}
    };

    int hargaFilm[3] = {50000, 48000, 45000};

    char makanan[3][20] = {"Popcorn", "Kentang Goreng", "Donat"};
    int hargaMakan[3] = {20000, 18000, 15000};

    char minum[3][20] = {"Milo Dino", "Blue Ocean Fizz", "Java Tea"};
    int hargaMinum[3] = {15000, 18000, 12000};

    // ===== VARIABEL =====
    int f, pilihFilm, pilihJam;
    int pilih, jumlah;
    char jawab, menu;

    int totalTiket = 0, totalFilm = 0;
    int totalMakan[3] = {0}, totalMinum[3] = {0};

    // ===== PESAN TIKET (WAJIB) =====
    printf("===== JADWAL FILM =====\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, film[i]);
        printf("   Jam ke-1 : %s\n", jadwal[i][0]);
        printf("   Jam ke-2 : %s\n", jadwal[i][1]);
        printf("   Harga   : Rp %d\n", hargaFilm[i]);
    }

    printf("\nPilih film (1-3): ");
    scanf("%d", &pilihFilm);
    f = pilihFilm - 1;

    printf("Pilih jam (1 = Jam ke-1, 2 = Jam ke-2): ");
    scanf("%d", &pilihJam);

    printf("Jumlah tiket: ");
    scanf("%d", &jumlah);

    totalTiket += jumlah;
    totalFilm += hargaFilm[f] * jumlah;

    // ===== LOOP PESANAN =====
    do {
        printf("\nMau pesan tambahan? (y/n): ");
        scanf(" %c", &jawab);

        if (jawab == 'y') {
            printf("Pesan apa? (t=tiket, m=makanan, n=minuman): ");
            scanf(" %c", &menu);

            // ===== TAMBAH TIKET =====
            if (menu == 't') {
                printf("\n===== JADWAL FILM =====\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i + 1, film[i]);
                    printf("   Jam ke-1 : %s\n", jadwal[i][0]);
                    printf("   Jam ke-2 : %s\n", jadwal[i][1]);
                    printf("   Harga   : Rp %d\n", hargaFilm[i]);
                }

                printf("Pilih film: ");
                scanf("%d", &pilihFilm);
                f = pilihFilm - 1;

                printf("Pilih jam: ");
                scanf("%d", &pilihJam);

                printf("Jumlah tiket: ");
                scanf("%d", &jumlah);

                totalTiket += jumlah;
                totalFilm += hargaFilm[f] * jumlah;
            }

            // ===== TAMBAH MAKANAN =====
            else if (menu == 'm') {
                printf("\n===== MENU MAKANAN =====\n");
                for (int i = 0; i < 3; i++)
                    printf("%d. %s - Rp %d\n", i + 1, makanan[i], hargaMakan[i]);

                printf("Pilih makanan: ");
                scanf("%d", &pilih);
                printf("Jumlah: ");
                scanf("%d", &jumlah);

                totalMakan[pilih - 1] += jumlah;
            }

            // ===== TAMBAH MINUMAN =====
            else if (menu == 'n') {
                printf("\n===== MENU MINUMAN =====\n");
                for (int i = 0; i < 3; i++)
                    printf("%d. %s - Rp %d\n", i + 1, minum[i], hargaMinum[i]);

                printf("Pilih minuman: ");
                scanf("%d", &pilih);
                printf("Jumlah: ");
                scanf("%d", &jumlah);

                totalMinum[pilih - 1] += jumlah;
            }
        }

    } while (jawab == 'y');

    // ===== STRUK =====
    printf("\n=======================================\n");
    printf("         STRUK PEMESANAN BIOSKOP         \n");
    printf("=========================================\n");

    printf("Film        : %s\n", film[f]);
    printf("Jam Tayang  : Jam ke-%d (%s)\n", pilihJam, jadwal[f][pilihJam - 1]);
    printf("Jumlah Tiket: %d\n", totalTiket);
    printf("Total Tiket : Rp %d\n", totalFilm);

    int totalBayar = totalFilm;

    printf("\n--- Makanan ---\n");
    for (int i = 0; i < 3; i++) {
        if (totalMakan[i] > 0) {
            int sub = totalMakan[i] * hargaMakan[i];
            printf("%s x %d = Rp %d\n", makanan[i], totalMakan[i], sub);
            totalBayar += sub;
        }
    }

    printf("\n--- Minuman ---\n");
    for (int i = 0; i < 3; i++) {
        if (totalMinum[i] > 0) {
            int sub = totalMinum[i] * hargaMinum[i];
            printf("%s x %d = Rp %d\n", minum[i], totalMinum[i], sub);
            totalBayar += sub;
        }
    }

    printf("------------------------------\n");
    printf("TOTAL BAYAR : Rp %d\n", totalBayar);
    printf("==============================\n");

    printf("\nTerima kasih! ENJOY YAW\n");

    return 0;
}
