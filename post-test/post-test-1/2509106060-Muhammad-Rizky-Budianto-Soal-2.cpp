#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    mahasiswa mhs[5];
    for (int i = 0; i < 5; i++) {
        cout << "===============================" << endl;
        cout << "Input data mahasiswa ke-" << i+1 << endl;
        cout << "===============================" << endl;
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";getline(cin, mhs[i].nama);
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";getline(cin, mhs[i].nim);
        cout << "Masukkan IPK mahasiswa ke-" << i+1 << ": ";cin >> mhs[i].ipk;
        cout << "===============================" << endl;
        cout << endl;
        cin.ignore();
    }

    float tinggi = mhs[0].ipk;
    int tertinggi = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > tinggi) {
            tinggi = mhs[i].ipk;
            tertinggi = i;
        }
    }
    
    cout << "##################################################################################" << endl;
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "===============================" << endl;
        cout << "Data mahasiswa ke-" << i+1 << endl;
        cout << "===============================" << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "IPK: " << mhs[i].ipk << endl;
        cout << "===============================" << endl;
        cout << endl;
    }
    cout << "Mahasiswa dengan IPK tertinggi adalah " << mhs[tertinggi].nama << " dengan NIM " << mhs[tertinggi].nim << " dan total IPK : " << mhs[tertinggi].ipk << endl;
    return 0;
}