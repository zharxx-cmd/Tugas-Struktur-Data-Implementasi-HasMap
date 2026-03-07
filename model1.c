#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char judul[100];
    char penulis[50];
    char penerbit[50];
    int tahun;
    char kategori[30];
} Buku;

void siapkanData() {
    Buku daftarBuku[5] = {
        {1, "Yowis Ben", "Bayu Skak", "KPG", 2021, "Slice of Life"},
        {2, "Animal Farm", "George Orwel", "Norris Classics", 2025, "Politics"},
        {3, "Princess Tales", "Jostein Gaarder", "Mizan", 2019, "Fantasi"},
        {4, "Presidents Orders", "Yuli Pritania", "Grasindo", 2017, "Detektif"},
        {5, "Rahasia Tergelap", "Lexie Xu", "Mizan", 2022, "Thriller"}
    };

    printf("Buku Pertama: %s oleh %s\n", daftarBuku[0].judul, daftarBuku[0].penulis);
}

int main() {
    siapkanData();
    return 0;
}