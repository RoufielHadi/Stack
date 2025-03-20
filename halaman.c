/*
Author: Roufiel Hadi  
NIM: 241524028  
Kelas: 1A  
Prodi: Sarjana Terapan Teknik Informatika  
Jurusan: Teknik Komputer dan Informatika  
Politeknik Negeri Bandung  
*/

#include "halaman.h"

#ifdef _WIN32
    #define clearScreen() system("cls")
#else
    #define clearScreen() system("clear")
#endif

void menuUtama() {
    int choice;
    do {
        clearScreen();
        puts("************************** APLIKASI BILANGAN BINER **************************");
        puts("1. Konversi Bilangan");
        puts("0. Keluar");
        printf("Pilihan: ");

        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
            case 1:
                menuKonversi();
                break;
            case 0:
                puts("\nTerima kasih telah menggunakan aplikasi ini!\n");
                break;
            default:
                puts("\nPilihan tidak valid! Silakan coba lagi.");
        }
    } while (choice != 0);
}

void menuKonversi() {
    int choice;
    char biner[32];  // Maksimal 32 bit
    int hasil;
    Stack S;

    do {
        clearScreen();
        puts("************************** KONVERSI BILANGAN **************************");
        puts("1. Desimal ke Biner");
        puts("2. Biner ke Desimal");
        puts("0. Kembali ke Menu Utama");
        printf("Pilihan: ");

        while (scanf("%d", &choice) != 1) {
            printf("Input tidak valid! Masukkan angka: ");
            while (getchar() != '\n');
        }
        getchar();

        switch (choice) {
			case 1: {
			    int num;
			    printf("\nMasukkan bilangan desimal: ");
			    scanf("%d", &num);
			    desimalKeBinerStack(num, &S);
			    printf("Hasil dalam biner: ");
			    TampilStack(S);
			    
			    printf("\nTekan Enter untuk melanjutkan...");
			    getchar();
			    getchar(); // Tambahan agar tidak langsung lanjut ke menu
			    break;
			}
			case 2:
			    printf("\nMasukkan bilangan biner: ");
			    scanf("%s", biner);
			
			    // Memasukkan tiap karakter ke stack
			    CreateStack(&S);
			    for (int i = 0; biner[i] != '\0'; i++) {
			        Push(&S, biner[i] - '0'); // Konversi dari char ke int
			    }
			
			    binerKeDesimalStack(&S, &hasil);
			    printf("Hasil dalam desimal: %d\n", hasil);
			    
			    printf("\nTekan Enter untuk melanjutkan...");
			    getchar();
			    getchar(); // Tambahan agar pengguna harus menekan Enter
			    break;
            case 0:
                puts("\nKembali ke Menu Utama...");
                break;
            default:
                puts("\nPilihan tidak valid! Silakan coba lagi.");
        }
    } while (choice != 0);
}

void jalankanAplikasi() {
    menuUtama();
}

