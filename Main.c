#include <stdio.h>
#include <string.h>
#include "hashmap.h"

int main(){

    struct HashMap library;
    initHashMap(&library);

    Buku dataAwal[] = {
    {1,"Yowis Ben","Bayu Skak",2021},
    {2,"Animal Farm","George Orwell",2025},
    {3,"Princess Tales","Jostein Gaarder",2019},
    {4,"Presidents Orders","Yuli Pritania",2017},
    {5,"Rahasia Tergelap","Lexie Xu",2022}
};

int jumlahData = 5;

for(int i=0;i<jumlahData;i++){
    put(&library, dataAwal[i]);
}

    int pilihan;

    do{

        printf("\n=== PERPUSTAKAAN DIGITAL ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Cari Buku\n");
        printf("3. Hapus Buku\n");
        printf("4. Tampilkan Buku\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d",&pilihan);

        if(pilihan==1){

            Buku b;

            printf("ID Buku: ");
            scanf("%d",&b.id);
            getchar();

            printf("Judul: ");
            fgets(b.judul,sizeof(b.judul),stdin);
            b.judul[strcspn(b.judul,"\n")] = 0;

            printf("Penulis: ");
            fgets(b.penulis,sizeof(b.penulis),stdin);
            b.penulis[strcspn(b.penulis,"\n")] = 0;

            printf("Tahun: ");
            scanf("%d",&b.tahunTerbit);

            put(&library,b);
        }

        else if(pilihan==2){

            int id;
            printf("Masukkan ID Buku: ");
            scanf("%d",&id);

            get(&library,id);
        }

        else if(pilihan==3){

            int id;
            printf("Masukkan ID Buku: ");
            scanf("%d",&id);

            removeKey(&library,id);
        }

        else if(pilihan==4){
            display(&library);
        }

    }while(pilihan!=0);

    return 0;
}