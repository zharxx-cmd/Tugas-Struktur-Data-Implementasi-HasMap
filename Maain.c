#include <stdio.h>
#include <string.h>
#include "hashmap.h"

int main(){

    struct HashMap library;
    initHashMap(&library);

    int pilihan;
    char judul[100];
    char penulis[100];

    do{

        printf("\n=== PERPUSTAKAAN DIGITAL ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Cari Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Cek Buku\n");
        printf("5. Tampilkan Semua Buku\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan){

        case 1:

            printf("Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            printf("Penulis : ");
            fgets(penulis, sizeof(penulis), stdin);
            penulis[strcspn(penulis,"\n")] = 0;

            put(&library, judul, penulis);
            break;

        case 2:

            printf("Masukkan Judul : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            get(&library, judul);
            break;

        case 3:

            printf("Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            removeKey(&library, judul);
            break;

        case 4:

            printf("Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            if(containsKey(&library, judul)){
                printf("Buku tersedia\n");
            }else{
                printf("Buku tidak tersedia\n");
            }

            break;

        case 5:
            display(&library);
            break;

        }

    }while(pilihan != 0);

    return 0;
}