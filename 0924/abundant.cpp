
#include <iostream>
using namespace std;

int sum_proper_divisor(int n) {
    int sum = 0;
    for (int d = 1; d < n; d++) {
        if (n % d == 0) {
            sum += d;
        }
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    cout << "12";

    for (int n = 13; n <= N; n++) {
        if (sum_proper_divisor(n) > n) {
            cout << ", " << n;
        }
    }
    return 0;
}

