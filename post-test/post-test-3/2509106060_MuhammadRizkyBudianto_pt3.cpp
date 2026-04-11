#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
using namespace std;
#define MAX 100
int pilihan;
int queue[MAX];
string namapenumpang[MAX];
int front = -1, rear = -1;
int stack[MAX];
int top = -1;
bool isFullQ() { 
    return rear == MAX - 1; 
}
bool isEmptyQ() { 
    return front == -1 || front > rear; 
}
bool isEmptyS() { 
    return top == -1; 
}

struct jadwal{
    string nama;
    int nomor;
    string asal;
    string tujuan;
    string keberangkatan;
    string kedatangan;
    int harga;
};
    
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
    cout << "\n";
    cout << "================================================================================================================\n";
    cout << "| No | Nama Kereta        | KA   | Asal        | Tujuan      | Brkt  | Tiba  | Harga        |\n";
    cout << "================================================================================================================\n";

    for (int i = 0; i < n; i++) {
        jadwal* ptr = (arr + i);
        cout << "| " << setw(2) << i + 1 << " ";
        cout << "| " << setw(18) << left << ptr->nama;
        cout << "| " << setw(4) << ptr->nomor << " ";
        cout << "| " << setw(12) << ptr->asal;
        cout << "| " << setw(12) << ptr->tujuan;
        cout << "| " << setw(5) << ptr->keberangkatan << " ";
        cout << "| " << setw(5) << ptr->kedatangan << " ";
        cout << "| Rp" << setw(10) << ptr->harga << "|\n";
    }

    cout << "================================================================================================================\n";
}

void tampilkan(jadwal* arr, int n) {
    if (n == 0) {
        cout << "Belum ada data kereta." << endl;
        getch();
        return;
    }
    read(arr, n);
    getch();
}

void update(jadwal* arr, int &n) {
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
    int jumlah = 0;

    for (int i = 0; i < n; i++) { 
        if ((arr + i)->asal == target1 && (arr + i)->tujuan == target2) { 
            hasil[jumlah] = *(arr + i); 
            jumlah++; 
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

void exitProgram() {
    cout << "========================================\n";
    cout << "       Terima kasih! Program selesai\n";
    cout << "========================================\n";
}

void enqueue(int value, string nama) {
    if (isFullQ()) {
        cout << "Antrian penuh!" << endl;
        cout << "tekan enter untuk kembali ke menu..." << endl;
        getch();
        return;
    }
    if (isEmptyQ()) front = 0;
    rear++;
    queue[rear] = value;
    namapenumpang[rear] = nama;
}

int dequeue() {
    if (isEmptyQ()) {
        cout << "Antrian kosong!" << endl;
            cout << "tekan enter untuk kembali ke menu..." << endl;
            getch();
        return -1;
    }
    int value = queue[front];
    front++;
    if (isEmptyQ()) front = rear = -1;
    return value;
}

void push(int value) {
    if (top >= MAX - 1) {
        cout << "Riwayat penuh!" << endl;
        cout << "tekan enter untuk kembali ke menu..." << endl;
        getch();
        return;
    }
    top++;
    stack[top] = value;
}

int pop() {
    cout << "\n============================================================\n";
    cout << "                PEMBATALAN TRANSAKSI TERAKHIR\n";
    cout << "============================================================\n";

    if (isEmptyS()) {
        cout << "| Tidak ada riwayat untuk dibatalkan!                    |\n";
        cout << "============================================================\n";
        getch();
        return -1;
    }

    int value = stack[top];
    top--;

    cout << "| Transaksi terakhir berhasil dibatalkan                 |\n";
    cout << "| Nomor KA : " << setw(40) << left << value << "|\n";
    cout << "============================================================\n";
    cout << "Tekan tombol apapun untuk kembali...";
    getch();

    return value;
}

void proses(jadwal *arr) {
    cout << "\n============================================================\n";
    cout << "                  PROSES ANTRIAN TIKET\n";
    cout << "============================================================\n";

    if (isEmptyQ()) {
        cout << "| Tidak ada antrian yang bisa diproses!                  |\n";
        cout << "============================================================\n";
        getch();
        return;
    }

    int idx = front;
    int nomor = dequeue();

    if (nomor == -1) return;

    bool ketemu = false;

    for (int i = 0; i < Jumlahkereta; i++) {
        if ((arr + i)->nomor == nomor) {
            cout << "| Penumpang : " << setw(40) << left << namapenumpang[idx] << "|\n";
            cout << "| Rute      : " << setw(40) << ((arr + i)->asal + " -> " + (arr + i)->tujuan) << "|\n";
            cout << "------------------------------------------------------------\n";
            cout << "| Status    : Tiket berhasil diproses                      |\n";
            ketemu = true;
            push(nomor);
            break;
        }
    }

    if (!ketemu) {
        cout << "| Status    : Nomor kereta tidak ditemukan!               |\n";
    }

    cout << "============================================================\n";
    cout << "Tekan tombol apapun untuk kembali...";
    getch();
}

void Antrian(jadwal *arr) {
    if (isEmptyQ()) {
        cout << "Antrian kosong\n";
        getch();
        return;
    }

    cout << "\n============================================================\n";
    cout << "| No | Nama Penumpang | Rute                              |\n";
    cout << "============================================================\n";

    int no = 1;

    for (int i = front; i <= rear; i++) {
        for (int j = 0; j < Jumlahkereta; j++) {
            if (*(queue + i) == (arr + j)->nomor) {
                cout << "| " << setw(2) << no++ << " ";
                cout << "| " << setw(15) << *(namapenumpang + i);
                cout << "| " << (arr + j)->asal << " -> " << (arr + j)->tujuan;

                int panjang = (arr + j)->asal.length() + (arr + j)->tujuan.length() + 4;
                for (int k = panjang; k < 30; k++) cout << " ";

                cout << "|\n";
            }
        }
    }

    cout << "============================================================\n";
    getch();
}

void Riwayat(jadwal *arr) {
    if (isEmptyS()) {
        cout << "Riwayat kosong\n";
        getch();
        return;
    }

    cout << "\n============================================================\n";
    cout << "| No | Nama Kereta        | Rute                          |\n";
    cout << "============================================================\n";

    int no = 1;

    for (int i = top; i >= 0; i--) {
        for (int j = 0; j < Jumlahkereta; j++) {
            if (*(stack + i) == (arr + j)->nomor) {
                cout << "| " << setw(2) << no++ << " ";
                cout << "| " << setw(18) << (arr + j)->nama;
                cout << "| " << (arr + j)->asal << " -> " << (arr + j)->tujuan;

                int panjang = (arr + j)->asal.length() + (arr + j)->tujuan.length() + 4;
                for (int k = panjang; k < 30; k++) cout << " ";

                cout << "|\n";
            }
        }
    }

    cout << "============================================================\n";
    getch();
}

void peek(jadwal *arr) {
    cout << "\n============================================================\n";
    cout << "                     INFORMASI DATA\n";
    cout << "============================================================\n";

    if (!isEmptyQ()) {
        for (int j = 0; j < Jumlahkereta; j++) {
            if (queue[front] == (arr + j)->nomor) {
                cout << "| Antrian Terdepan                                      |\n";
                cout << "| Nama : " << setw(42) << left << namapenumpang[front] << "|\n";
                cout << "| Rute : " << setw(42) << ((arr + j)->asal + " -> " + (arr + j)->tujuan) << "|\n";
                cout << "------------------------------------------------------------\n";
            }
        }
    } else {
        cout << "| Antrian kosong                                        |\n";
    }

    if (!isEmptyS()) {
        for (int j = 0; j < Jumlahkereta; j++) {
            if (stack[top] == (arr + j)->nomor) {
                cout << "| Transaksi Terakhir                                    |\n";
                cout << "| Kereta : " << setw(40) << left << (arr + j)->nama << "|\n";
                cout << "| Rute   : " << setw(40) << ((arr + j)->asal + " -> " + (arr + j)->tujuan) << "|\n";
            }
        }
    } else {
        cout << "| Riwayat kosong                                        |\n";
    }

    cout << "============================================================\n";
    cout << "Tekan tombol apapun untuk kembali...";
    getch();
}

int main() {
    string nama;
    int nomor;
    do {
        system("cls");
        cout << "============================================================\n";
        cout << "           SISTEM MANAJEMEN KEBERANGKATAN KERETA\n";
        cout << "============================================================\n";
        cout << "---------------------- MENU UTAMA --------------------------\n";
        cout << "| 1  | Lihat Semua Jadwal Kereta                          |\n";
        cout << "| 2  | Tambah Data Kereta                                 |\n";
        cout << "| 3  | Cari Berdasarkan Rute                              |\n";
        cout << "| 4  | Cari Berdasarkan Nomor KA                          |\n";
        cout << "| 5  | Urutkan Nama Kereta (A-Z)                          |\n";
        cout << "| 6  | Urutkan Harga Termurah                             |\n";
        cout << "------------------------------------------------------------\n";
        cout << "| 7  | Pesan Tiket                                        |\n";
        cout << "| 8  | Proses Antrian                                     |\n";
        cout << "| 9  | Tampilkan Antrian                                  |\n";
        cout << "| 10 | Tampilkan Riwayat                                  |\n";
        cout << "| 11 | Batalkan Transaksi Terakhir                        |\n";
        cout << "| 12 | Lihat Data Terdepan / Terakhir (Peek)              |\n";
        cout << "------------------------------------------------------------\n";
        cout << "| 13 | Keluar                                             |\n";
        cout << "============================================================\n";
        cout << "Pilih menu [1-13] : ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: system("cls");
            tampilkan(jadwal_Kereta, Jumlahkereta);
            break;
            case 2: system("cls");
            update(jadwal_Kereta, Jumlahkereta);
            break;
            case 3: system("cls");
            linear(jadwal_Kereta, Jumlahkereta);
            break;
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
                break;
            }
            case 5: system("cls");
            tampilmerge(jadwal_Kereta, Jumlahkereta); 
            break;
            case 6: system("cls");
            selection(jadwal_Kereta, Jumlahkereta);
            break;
            case 7:
            system("cls");
            cout << "============================================================\n";
            cout << "                    PEMESANAN TIKET KERETA\n";
            cout << "============================================================\n";
            cout << "Masukkan Nama Penumpang : ";
            getline(cin, nama);
            cout << "\n------------------ DAFTAR KERETA TERSEDIA ------------------\n";
            read(jadwal_Kereta, Jumlahkereta);
            cout << "\nMasukkan Nomor Kereta (KA) yang dipilih : ";
            cin >> nomor;
            cin.ignore();
            enqueue(nomor, nama);
            cout << "\n============================================================\n";
            cout << "| Status : Pemesanan Berhasil                              |\n";
            cout << "| Nama   : " << setw(40) << left << nama << "|\n";
            cout << "| KA     : " << setw(40) << nomor << "|\n";
            cout << "------------------------------------------------------------\n";
            cout << "| Silakan tunggu proses antrian Anda...                    |\n";
            cout << "============================================================\n";
            cout << "Tekan tombol apapun untuk kembali...";
            getch();
            break;
            case 8: system("cls");
             proses(jadwal_Kereta); 
             break;
            case 9: system("cls");
            Antrian(jadwal_Kereta); 
            break;
            case 10: system("cls"); 
            Riwayat(jadwal_Kereta); 
            break;
            case 11: system("cls");
            pop(); 
            break;
            case 12: system("cls");
            peek(jadwal_Kereta); 
            break;
            case 13: system("cls");
            exitProgram();
            break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 13);

    return 0;
}