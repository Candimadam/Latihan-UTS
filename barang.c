#include <stdio.h>
#include <stdbool.h>

struct Barang {
    int id;
    char nama[50];
    int jumlah;
};

struct Barang kumpulanBarang[100];
int jumlah_barang = 0;

void tambahBarang() {
    if(jumlah_barang > 100) {
        printf("Data barang ini sudah mencapai batas maksimal!\n");
        return;
    }
    struct Barang barangBaru;

    printf("Masukan ID barang: ");
    scanf("%d", &barangBaru.id);

    printf("Masukan nama barang: ");
    scanf(" %[^\n]s", barangBaru.nama);

    printf("Masukan jumlah barang: ");
    scanf("%d", &barangBaru.jumlah);

    kumpulanBarang[jumlah_barang++] = barangBaru;
    printf("Data barang sudah masuk!\n");
    }

void tampilkanBarang() {
    printf("\n+-------+-----------------+--------+\n");
    printf("| %-5s | %-15s | %-4s |\n", "ID","Nama Barang", "Jumlah");
    printf("+-------+-----------------+--------+");
    for(int i = 0; i < jumlah_barang; i++) {
        printf("\n| %-5d | %-15s | %-6d |", kumpulanBarang[i].id, kumpulanBarang[i].nama, kumpulanBarang[i].jumlah);
    }
    printf("\n+-------+-----------------+--------+\n");
}

void cariBarangBerdasarkanId() {
    int idDicari;
    bool ketemu = false;

    printf("\nMasukan ID barang yang ingin dicari: ");
    scanf("%d", &idDicari);

    for(int i = 0; i < jumlah_barang; i++) {
        if(idDicari == kumpulanBarang[i].id) {
            ketemu = true;
            printf("\n| %-5d | %-15s | %-6d |", kumpulanBarang[i].id, kumpulanBarang[i].nama, kumpulanBarang[i].jumlah);
        }
    } if(!ketemu) {
         printf("Data nama barang dengan ID %d tidak ada!\n", idDicari);
    }
}

void urutkanBarangBerdasarkanId() {
    if(jumlah_barang == 0) {
        printf("Tidak ada data nama barang...\n");
        return;
    }
    int i, j;
    struct Barang temp;
    for (i = 0; i < jumlah_barang - 1; i++)
    {
        for (j = 0; j < jumlah_barang - i - 1; j++)
        {
            if (kumpulanBarang[j].id > kumpulanBarang[j + 1].id)
            {
                temp = kumpulanBarang[j];
                kumpulanBarang[j] = kumpulanBarang[j + 1];
                kumpulanBarang[j + 1] = temp;
            }
        }
    }

    printf("Data nama barang berhasil diurutkan berdasarkan ID, berikut adalah datanya:");
    tampilkanBarang();
    }

int main() {
    bool jalan = true;
    int pilihan;

    do {
        printf("Tampilan Pilihan Daftar Menu");
        printf("\n1. Tambah barang");
        printf("\n2. Tampilkan barang");
        printf("\n3. Cari nama barang berdasarkan ID");
        printf("\n4. Urutkan nama barang berdasarkan ID");
        printf("\n5. Keluar program");
        printf("\nMasukan pilihan: ");
        scanf("%d", &pilihan);

        if(pilihan == 1) {
            tambahBarang();
        } else if(pilihan == 2) {
            tampilkanBarang();
        } else if(pilihan == 3) {
            cariBarangBerdasarkanId();
        } else if(pilihan == 4) {
            urutkanBarangBerdasarkanId();
        } else if(pilihan == 5) {
            jalan = false;
        }

        printf("\nTekan apapun untuk melanjutkan...");
        getchar();
        getchar();

    } while(jalan);
    return 0;
}