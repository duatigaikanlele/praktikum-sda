#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct jadwal{
    string nama;
    int nomor;
    string asal;
    string tujuan;
    string keberangkatan;
    string kedatangan;
    int harga;
};
    
#define MAX 30
jadwal jadwal_Kereta[MAX] = {
    {"Argo Wilis", 325, "Bandung", "Surabaya", "08:00", "14:00", 150000},
    {"Argo Parahyangan", 412, "Bandung", "Jakarta", "09:00", "12:00", 100000},
    {"Dukhon Bromo Anggrek", 645, "Surabaya", "Jakarta", "10:00", "16:00", 200000},
    {"Kraton Lawu", 121, "Solo", "Jakarta", "11:00", "17:00", 180000},
    {"Bima Dwipangga", 223, "Yogyakarta", "Jakarta", "12:00", "18:00", 170000},
    {"Argo Jati", 45, "Cirebon", "Jakarta", "15:00", "18:30", 120000},
    {"Renjana Sindoro", 511, "Semarang", "Jakarta", "13:00", "19:00", 160000},
    {"Cakrawala Muria", 257, "Semarang", "Bandung", "14:00", "20:00", 155000},
    {"Argo Cheribon", 654, "Jakarta", "Cirebon", "16:00", "19:30", 125000},
    {"Bumi Anjasmoro", 819, "Surabaya", "Semarang", "17:00", "22:00", 140000}
};
int Jumlahkereta = 10;

void swap(jadwal* a, jadwal* b) {
    jadwal temp = *a;
    *a = *b;
    *b = temp;
}

void read(jadwal* arr, int n) {
    cout << "\n==============================================================\n";
    cout << "                    DAFTAR JADWAL KERETA\n";
    cout << "==============================================================\n";

    cout << left
         << setw(4)  << "No"
         << setw(20) << "Nama Kereta"
         << setw(6)  << "KA"
         << setw(12) << "Asal"
         << setw(12) << "Tujuan"
         << setw(8)  << "Brkt"
         << setw(8)  << "Tiba"
         << setw(10) << "Harga\n";

    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        jadwal* ptr = (arr + i);
        cout << setw(4)  << i + 1
             << setw(20) << ptr->nama
             << setw(6)  << ptr->nomor
             << setw(12) << ptr->asal
             << setw(12) << ptr->tujuan
             << setw(8)  << ptr->keberangkatan
             << setw(8)  << ptr->kedatangan
             << "Rp" << setw(8) << ptr->harga << endl;
    }

    cout << "==============================================================\n";
}

void tampilkan(jadwal* arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        getch();
        return;
    }
    read(arr, n);
    getch();
}

void update(jadwal* arr, int &n) {
    system("cls");
    if (n >= MAX) {
        cout << "Kapasitas data untuk Kereta sudah penuh!" << endl;
        return;
    }
    cout << "=============================\n";
    cout << "      TAMBAH DATA KERETA\n";
    cout << "=============================\n\n";

    cout << "Nama Kereta     : "; 
    getline(cin, (arr + n)->nama);

    cout << "  Nomor kereta  : "; 
    while(!(cin >> (arr + n)->nomor)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Input salah! Masukkan angka: ";
    }
    cin.ignore();

    cout << "Asal            : "; 
    getline(cin, (arr + n)->asal);

    cout << "Tujuan          : "; 
    getline(cin, (arr + n)->tujuan);

    cout << "Jam Berangkat   : "; 
    getline(cin, (arr + n)->keberangkatan);

    cout << "Jam Kedatangan  : "; 
    getline(cin, (arr + n)->kedatangan);

    cout << "Harga Tiket     : "; 
    cin >> (arr + n)->harga;

    n++;
    system("cls");
    cout << "Data kereta berhasil ditambahkan!" << endl;
    getch();
}

void merge(jadwal* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    jadwal* L = new jadwal[n1];
    jadwal* R = new jadwal[n2];

    for (int i = 0; i < n1; i++)
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++)
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if ((L + i)->nama <= (R + j)->nama) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = *(L + i);
        i++; k++;
    }

    while (j < n2) {
        *(arr + k) = *(R + j);
        j++; k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(jadwal* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void tampilmerge(jadwal* arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }
    mergeSort(arr, 0, n - 1);
    cout << "Data berhasil diurutkan berdasarkan Nama Kereta!" << endl;
    cout << "tekan enter untuk melihat hasil..." << endl;
    getch();
    tampilkan(arr, n);
}

void linear(jadwal* arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }

    string target1, target2;
    cin.ignore();

    cout << "=============================\n";
    cout << "       CARI BERDASARKAN RUTE\n";
    cout << "=============================\n";

    cout << "Masukkan Asal   : "; 
    getline(cin, target1);
    cout << "Masukkan Tujuan : "; 
    getline(cin, target2);

    jadwal hasil[MAX];
    int jumlah = 0; //menyimpan jumlah data yang cocok

    for (int i = 0; i < n; i++) { //iterasi dari data pertama sampai terakhir, mengambil 1 data kereta: arr[i], membandingkan asal dan tujuan dengan input user
        if ((arr + i)->asal == target1 && (arr + i)->tujuan == target2) { //cek apakah data cocok
            hasil[jumlah] = *(arr + i); //jika cocok, simpan ke array hasil
            jumlah++; //tambah jumlah data yang ditemukan
        }
    }

    system("cls");

    if (jumlah > 0) { 
        read(hasil, jumlah); 
    } else {
        cout << "Tidak ditemukan kereta dengan rute tersebut." << endl;
    }

    getch();
}

void sorting(jadwal *arr, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if((arr+i)->nomor > (arr+j)->nomor) {
                swap((arr+i), (arr+j));
            }
        }
    }
}

int jumpSearch(jadwal *arr, int n, int target) {
    int step = (int)sqrt((double)n);
    int prev = 0;

    while (step < n && (arr + step - 1)->nomor < target) {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n)
            return -1;
    }

    int batas = step;
    if (batas > n) batas = n;

    while (prev < batas) {
        if ((arr + prev)->nomor == target)
            return prev;
        prev++;
    }

    return -1;
}

void selection(jadwal *arr, int n) {
    system("cls");
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIdx)->harga) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr + i, arr + minIdx);
        }
    }

    cout << "Data berhasil diurutkan berdasarkan Harga Tiket (Termurah)!" << endl;
    cout << "tekan enter untuk melihat hasil..." << endl;
    getch();
    tampilkan(arr, n);
}

int main() {
    system("cls");
    int pilihan;
    do {
        cout << "\n============================================\n";
        cout << "   SISTEM MANAJEMEN KEBERANGKATAN KERETA API\n";
        cout << "============================================\n";
        cout << "1. Tampil Jadwal Semua Kereta\n";
        cout << "2. Tambah Data Kereta\n";
        cout << "3. Cari Berdasarkan Rute\n";
        cout << "4. Cari Berdasarkan Nomor KA\n";
        cout << "5. Urutkan Nama (A-Z)\n";
        cout << "6. Urutkan Harga Termurah\n";
        cout << "7. Keluar\n";
        cout << "\nPilih menu: "; cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tampilkan(jadwal_Kereta, Jumlahkereta); system("cls"); break;
            case 2: update(jadwal_Kereta, Jumlahkereta); system("cls"); break;
            case 3: linear(jadwal_Kereta, Jumlahkereta); system("cls"); break;
            case 4: {
                system("cls");
                int cari;
                cout << "Masukkan Nomor Kereta Api(KA) yang dicari: ";
                cin >> cari;
                cin.ignore();
                sorting(jadwal_Kereta, Jumlahkereta);
                int hasil = jumpSearch(jadwal_Kereta, Jumlahkereta, cari);
                if (hasil != -1) {
                    system("cls");
                    cout << "Nomor kereta(KA) ditemukan:\n";
                    cout << "tekan enter untuk melihat hasil..." << endl;
                    getch();
                    tampilkan(jadwal_Kereta + hasil, 1);
                } else {
                    system("cls");
                    cout << "Nomor kereta(KA) tidak ditemukan.\n";
                    cout << "tekan enter untuk kembali ke menu..." << endl;
                    getch();
                }
                system("cls");
                break;
            }
            case 5: tampilmerge(jadwal_Kereta, Jumlahkereta); system("cls"); break;
            case 6: selection(jadwal_Kereta, Jumlahkereta); system("cls"); break;
            case 7:
                system("cls");
                cout << "========================================\n";
                cout << "       Terima kasih! Program selesai\n";
                cout << "========================================\n";
                break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 7);

    return 0;
}