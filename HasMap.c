#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

int hashFunction(char *key){
    int sum = 0;
    for(int i = 0; key[i] != '\0'; i++){
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void initHashMap(struct HashMap* map){
    for(int i = 0; i < TABLE_SIZE; i++){
        map->table[i] = NULL;
    }
}

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

}

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