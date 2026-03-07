#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int hashFunction(int key){
    return key % TABLE_SIZE;
}

void initHashMap(struct HashMap* map){
    for(int i=0;i<TABLE_SIZE;i++){
        map->table[i] = NULL;
    }
}

void put(struct HashMap* map, Buku buku){

    int index = hashFunction(buku.id);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = buku;
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
}

void get(struct HashMap* map, int id){

    int index = hashFunction(id);
    struct Node* temp = map->table[index];

    while(temp != NULL){

        if(temp->data.id == id){

            printf("ID     : %d\n",temp->data.id);
            printf("Judul  : %s\n",temp->data.judul);
            printf("Penulis: %s\n",temp->data.penulis);
            printf("Tahun  : %d\n",temp->data.tahunTerbit);

            return;
        }

        temp = temp->next;
    }

    printf("Buku tidak ditemukan\n");
}

void removeKey(struct HashMap* map, int id){

    int index = hashFunction(id);

    struct Node* temp = map->table[index];
    struct Node* prev = NULL;

    while(temp != NULL){

        if(temp->data.id == id){

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

int containsKey(struct HashMap* map, int id){

    int index = hashFunction(id);
    struct Node* temp = map->table[index];

    while(temp != NULL){

        if(temp->data.id == id){
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void display(struct HashMap* map){

    printf("\nDaftar Buku:\n");

    for(int i=0;i<TABLE_SIZE;i++){

        struct Node* temp = map->table[i];

        while(temp != NULL){

            printf("ID:%d | Judul:%s | Penulis:%s | Tahun:%d\n",
                   temp->data.id,
                   temp->data.judul,
                   temp->data.penulis,
                   temp->data.tahunTerbit);

            temp = temp->next;
        }
    }
}