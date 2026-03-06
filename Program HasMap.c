#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node untuk chaining
struct Node{
    char judul[100];
    char penulis[100];
    struct Node* next;
};

struct HashMap{
    struct Node* table[TABLE_SIZE];
};

// fungsi hash
int hashFunction(char *key){
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++){
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// inisialisasi hashmap
void initHashMap(struct HashMap* map){
    for(int i = 0; i < TABLE_SIZE; i++){
        map->table[i] = NULL;
    }
}

// tambah buku
void put(struct HashMap* map, char *judul, char *penulis){
    int index = hashFunction(judul);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->judul, judul);
    strcpy(newNode->penulis, penulis);
    newNode->next = NULL;

    if(map->table[index] == NULL){
        map->table[index] = newNode;
    }else{
        struct Node* temp = map->table[index];
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Buku berhasil ditambahkan\n");
}

// cari buku
void get(struct HashMap* map, char *judul){
    int index = hashFunction(judul);
    struct Node* temp = map->table[index];

    while(temp != NULL){
        if(strcmp(temp->judul, judul) == 0){
            printf("Judul   : %s\n", temp->judul);
            printf("Penulis : %s\n", temp->penulis);
            return;
        }
        temp = temp->next;
    }

    printf("Buku tidak ditemukan\n");
}

// hapus buku
void removeKey(struct HashMap* map, char *judul){
    int index = hashFunction(judul);
    struct Node* temp = map->table[index];
    struct Node* prev = NULL;

    while(temp != NULL){
        if(strcmp(temp->judul, judul) == 0){

            if(prev == NULL){
                map->table[index] = temp->next;
            }else{
                prev->next = temp->next;
            }

            free(temp);
            printf("Buku berhasil dihapus\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Buku tidak ditemukan\n");
}

// cek buku
int containsKey(struct HashMap* map, char *judul){
    int index = hashFunction(judul);
    struct Node* temp = map->table[index];

    while(temp != NULL){
        if(strcmp(temp->judul, judul) == 0){
            return 1;
        }
        temp = temp->next;
    }

    return 0;
}

// tampilkan semua buku
void display(struct HashMap* map){
    printf("\nDaftar Buku:\n");

    for(int i = 0; i < TABLE_SIZE; i++){
        struct Node* temp = map->table[i];

        while(temp != NULL){
            printf("Judul: %s | Penulis: %s\n", temp->judul, temp->penulis);
            temp = temp->next;
        }
    }
}

// main program
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
            printf("Masukkan Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            printf("Masukkan Penulis : ");
            fgets(penulis, sizeof(penulis), stdin);
            penulis[strcspn(penulis,"\n")] = 0;

            put(&library, judul, penulis);
            break;

        case 2:
            printf("Masukkan Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            get(&library, judul);
            break;

        case 3:
            printf("Masukkan Judul Buku : ");
            fgets(judul, sizeof(judul), stdin);
            judul[strcspn(judul,"\n")] = 0;

            removeKey(&library, judul);
            break;

        case 4:
            printf("Masukkan Judul Buku : ");
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