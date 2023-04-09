#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Mahasiswa
{
    char npm[20];
    char nama[30];
    float ipk;
};

struct Mahasiswa kumpulanMahasiswa[100];
int jumlah_mahasiswa = 0;

void tambahMahasiswa()
{
    if (jumlah_mahasiswa > 100)
    {
        printf("Data mahasiswa sudah mencapai batas!");
        return;
    }
    struct Mahasiswa mahasiswaBaru;

    printf("Masukan NPM mahasiswa: ");
    scanf(" %[^\n]s", mahasiswaBaru.npm);

    printf("Masukan nama mahasiswa: ");
    scanf(" %[^\n]s", mahasiswaBaru.nama);

    printf("Masukan IPK mahasiswa: ");
    scanf("%f", &mahasiswaBaru.ipk);

    kumpulanMahasiswa[jumlah_mahasiswa++] = mahasiswaBaru;
    printf("Data sudah masuk!\n");
}

void tampilkanMahasiswa()
{
    printf("\n+-----------------------------------------------------+\n");
    printf("| %-15s | %-20s | %-4s |\n", "NPM", "Nama", "IPK");
    printf("+-----------------------------------------------------+\n");

    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        printf("| %-15s | %-20s | %-.2f |\n", kumpulanMahasiswa[i].npm, kumpulanMahasiswa[i].nama, kumpulanMahasiswa[i].ipk);
    }

    printf("+-----------------------------------------------------+\n");
}


void cariMahasiswaBerdasarkanNpm()
{
    char npmDicari[11];
    bool ketemu = false;

    printf("Masukan NPM yang ingin dicari: ");
    scanf(" %[^\n]s", npmDicari);

    printf("\n+-----------------------------------------------------+\n");
    printf("| %-15s | %-20s | %-4s |\n", "NPM", "Nama", "IPK");
    printf("+-----------------------------------------------------+\n");
    for (int i = 0; i < jumlah_mahasiswa; i++)
    {
        if (strcmp(npmDicari, kumpulanMahasiswa[i].npm) == 0)
        {
            ketemu = true;
            printf("| %-15s | %-20s | %-.2f |\n", kumpulanMahasiswa[i].npm, kumpulanMahasiswa[i].nama, kumpulanMahasiswa[i].ipk);
        }
    }
     printf("+-----------------------------------------------------+\n");

    if (!ketemu)
    {
        printf("Data mahasiswa dengan npm %s tidak ada!\n", npmDicari);
    }
}

void urutkanMahasiswaBerdasarkanNpm()
{
    if (jumlah_mahasiswa == 0)
    {
        printf("Tidak ada data mahasiswa...\n");
        return;
    }
    int i, j;
    struct Mahasiswa temp;
    for (i = 0; i < jumlah_mahasiswa - 1; i++)
    {
        for (j = 0; j < jumlah_mahasiswa - i - 1; j++)
        {
            if (strcmp(kumpulanMahasiswa[j].npm, kumpulanMahasiswa[j + 1].npm) > 0)
            {
                temp = kumpulanMahasiswa[j];
                kumpulanMahasiswa[j] = kumpulanMahasiswa[j + 1];
                kumpulanMahasiswa[j + 1] = temp;
            }
        }
    }

    printf("Data mahasiswa berhasil diurutkan berdasarkan NPM, berikut adalah datanya:");
    tampilkanMahasiswa();
}

int main()
{
    bool jalan = true;
    int pilihan;

    do
    {
        printf("\e[1;1H\e[2J");
        printf("Tampilan Pilihan Menun");
        printf("\n1. Tambah mahasiswa");
        printf("\n2. Tampilkan data mahasiswa");
        printf("\n3. Cari mahasiswa berdasarkan NPM");
        printf("\n4. Urutkan Mahasiswa berdasarkan NPM");
        printf("\n5. Keluar program");
        printf("\nMasukan pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            tambahMahasiswa();
        }
        else if (pilihan == 2)
        {
            tampilkanMahasiswa();
        }
        else if (pilihan == 3)
        {
            cariMahasiswaBerdasarkanNpm();
        }
        else if (pilihan == 4)
        {
            urutkanMahasiswaBerdasarkanNpm();
        }
        else if (pilihan == 5)
        {
            jalan = false;
        }

        printf("Tekan apapun untuk melanjutkan...");
        getchar();
        getchar();

    } while (jalan);
    return 0;
}