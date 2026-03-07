#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLE_SIZE 10

typedef struct{
    int id;
    char judul[100];
    char penulis[100];
    int tahunTerbit;
} Buku;

struct Node{
    Buku data;
    struct Node* next;
};

struct HashMap{
    struct Node* table[TABLE_SIZE];
};

void initHashMap(struct HashMap* map);
int hashFunction(int key);

void put(struct HashMap* map, Buku buku);
void get(struct HashMap* map, int id);
void removeKey(struct HashMap* map, int id);
int containsKey(struct HashMap* map, int id);

void display(struct HashMap* map);

#endif