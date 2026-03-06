#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLE_SIZE 10

// Node untuk chaining
struct Node{
    char judul[100];
    char penulis[100];
    struct Node* next;
};

// HashMap
struct HashMap{
    struct Node* table[TABLE_SIZE];
};

// deklarasi fungsi
void initHashMap(struct HashMap* map);
int hashFunction(char *key);
void put(struct HashMap* map, char *judul, char *penulis);
void get(struct HashMap* map, char *judul);
void removeKey(struct HashMap* map, char *judul);
int containsKey(struct HashMap* map, char *judul);
void display(struct HashMap* map);

#endif