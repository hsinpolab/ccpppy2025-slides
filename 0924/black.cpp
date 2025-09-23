
#include <iostream>
using namespace std;

void int2array(int n, int A[4]) {
    A[0] = n / 1000;
    A[1] = (n / 100) % 10;
    A[2] = (n / 10) % 10;
    A[3] = n % 10;
}

int array2int(int A[4]) {
    return 1000 * A[0] + 100 * A[1] + 10 * A[2] + A[3];
}

void sort(int N[4], int L[4], int S[4]) {
    L[0] = N[0];
    L[1] = N[1];
    L[2] = N[2];
    L[3] = N[3];
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < 3; i++) {
            if (L[i] < L[i+1]) {
                swap(L[i], L[i+1]);
                sorted = false;
            }
        }
    }
    S[0] = L[3];
    S[1] = L[2];
    S[2] = L[1];
    S[3] = L[0];
}

int main() {
    int n;
    int N[4] = {};
    int L[4] = {};
    int S[4] = {};
    cin >> n;
    int2array(n, N);
    while (n != 6174) {
        sort(N, L, S);
        int large = array2int(L);
        int small = array2int(S);
        n = large - small;
        cout << large << " - " << small << " = " << n << endl;
        int2array(n, N);
    }
}

