#include <iostream>
using namespace std;

int main() {
    int fib[8] = {1,1,2,3,5,8,13,21};
    int min = fib[0];
    int indeks = 0;
    for (int i = 0; i < 8; i++) {
        if (fib[i] < min) {
            min = fib[i];
            indeks = i;
        }
    }
    cout << "Nilai terkecil adalah " << min << endl;
    cout << "Indeksnya adalah " << indeks << endl;
    return 0;
}

// PSEUDOCODE:
// procedure FindMin(A : array of n elements) => 1
//   min ← A[0] => 1
//   for i ← 1 to n - 1 do => n
//     if A[i] < min then => n-1
//       min ← A[i] => 0/n-1
//     end if => n-1
//   end for => n
//   return min => 1
// end procedure => 1

// Tmin/Best Case :
// =- C1+C2+C3n+C4(n−1)+0+C6(n−1)+C7n+C8+C9
// = C1+C2+C3n+C4n-C4+C6n-C6+C7n+C8+C9
// = (C3+C4+C6+C7)n + (C1+C2-C4-C6+C8+C9)
// = 4n + 2
// = 4n => n => O(n)

// Tmax/Worst Case :
// = C1+C2+C3n+C4(n−1)+C5(n−1)+C6(n−1)+C7n+C8+C9
// = C1+C2+C3n+C4n-C4+C5n-C5+C6n-C6+C7n+C8+C9
// = (C3+C4+C5+C6+C7)n + (C1+C2-C4-C5-C6+C8+C9)
// = 5n + 1
// = 5n => n => O(n)