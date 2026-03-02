#include <iostream>
using namespace std;

void reverse(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
       int *start = &arr[i];
       int *end = &arr[n - 1 - i];
       int smntr = *start;
       *start = *end;
       *end = smntr;
        start++;
        end--;
    }
}

int main() {
    int arr[7] = {2,3,5,7,11,13,17};
    int n = 7;
    cout << "======================================================" << endl;
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n======================================================" << endl;
    cout << endl;
    reverse(arr, n);
    cout << "======================================================" << endl;
    cout << "Array setelah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n======================================================" << endl;
}