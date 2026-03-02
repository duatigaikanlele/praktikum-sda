#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int smntr = a;
    a = b;
    b = smntr;
}

int main() {
    int a, b;
    cout << "======================================================" << endl;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "======================================================" << endl;
    cout << endl;
    cout << "Nilai sebelum : a = " << a << ", b = " << b << endl;
    cout << "======================================================" << endl;
    cout << endl;
    tukar(a, b);
    cout << "======================================================" << endl;
    cout << "Nilai susudah : a = " << a << ", b = " << b << endl;
    cout << "======================================================" << endl;
}