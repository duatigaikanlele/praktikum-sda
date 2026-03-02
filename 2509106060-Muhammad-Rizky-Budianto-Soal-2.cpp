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

    float max = mhs[0].ipk;
    int maxindex = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > max) {
            max = mhs[i].ipk;
            maxindex = i;
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
    cout << "Mahasiswa dengan IPK tertinggi adalah " << mhs[maxindex].nama << " dengan NIM " << mhs[maxindex].nim << " dan total IPK : " << mhs[maxindex].ipk << endl;
    return 0;
}