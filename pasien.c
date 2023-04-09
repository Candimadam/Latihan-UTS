#include <stdio.h>
#include <stdbool.h>

struct Pasien {
    int id;
    char nama[30];
    int umur;
};

struct Pasien kumpulanPasien[100];
int jumlah_pasien = 0;

void tambahPasien() {
    if(jumlah_pasien > 100) {
        printf("Data pasien sudah mencapai batas! ");
        return;
    }
    struct Pasien pasienBaru;
    
    printf("Masukan pasien ID ");
    scanf("%d", &pasienBaru.id);
    
    printf("Masukan nama pasien ");
    scanf(" %[^\n]s", pasienBaru.nama);
    
    printf("Masukan umur pasien ");
    scanf("%d", &pasienBaru.umur);
    
    kumpulanPasien[jumlah_pasien++] = pasienBaru;
    printf("Data sudah masuk!\n");
    }
   
void tampilkanPasien() {
    printf("\n------------------------------------------\n");
    printf("ID\tNama\tUmur\n");
    for(int i = 0; i < jumlah_pasien; i++) {
        printf("\n%d\t%s\t%d", kumpulanPasien[i].id, kumpulanPasien[i].nama, kumpulanPasien[i].umur);
    }printf("\n------------------------------------------\n");
}

void cariPasienBerdasarkanId() {
    int idDicari;
    bool ketemu = false;
    
    printf("Masukan ID yang ingin dicari: ");
    scanf("%d", &idDicari);
    
    for(int i = 0; i < jumlah_pasien; i++) {
        if(idDicari == kumpulanPasien[i].id) {
            ketemu = true;
            printf("\n%d\t%s\t%d", kumpulanPasien[i].id, kumpulanPasien[i].nama, kumpulanPasien[i].umur);
        }
    } if(!ketemu) {
         printf("Data pasien dengan ID %d tidak ada!", idDicari);
    }
}

void urutkanPasienBerdasarkanId() {
    if(jumlah_pasien == 0) {
        printf("Tidak ada data pasien...");
        return;
    } 
    int i, j;
    struct Pasien temp;
    for (i = 0; i < jumlah_pasien - 1; i++)
    {
        for (j = 0; j < jumlah_pasien - i - 1; j++)
        {
            if (kumpulanPasien[j].id > kumpulanPasien[j + 1].id)
            {
                // Swap data
                temp = kumpulanPasien[j];
                kumpulanPasien[j] = kumpulanPasien[j + 1];
                kumpulanPasien[j + 1] = temp;
            }
        }
    }

    printf("Data pasien berhasil diurutkan berdasarkan ID, berikut adalah datanya:");
    tampilkanPasien();
    }
   
int main() {
    bool jalan = true;
    int pilihan;

    do {
        printf("Tampilan Pilihan Menu");
        printf("\n!. Tambah pasien");
        printf("\n2. Tampilkan pasien");
        printf("\n3. Cari pasien berdasarkan ID");
        printf("\n4. Urutkan pasien berdasarkan ID");
        printf("\n5. Keluar program");
        printf("\nMasukan pilihan: ");
        scanf("%d", &pilihan);

        if(pilihan == 1) {
            tambahPasien();
        } else if(pilihan == 2) {
            tampilkanPasien();
        } else if(pilihan == 3) {
            cariPasienBerdasarkanId();
        } else if(pilihan == 4) {
            urutkanPasienBerdasarkanId();
        } else if(pilihan == 5) {
            jalan = false;
        }

    } while(jalan);
    return 0;
}