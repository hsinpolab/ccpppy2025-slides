
#include <iostream>
using namespace std;

int next_step(int n) {
    if (n % 2 == 0) return n / 2;
    else return 3 * n + 1;
}

int main () {
    int n;
    int step = 0;
    cin >> n;

    while (n != 1) {
        n = next_step(n);
        step++;
        cout << n << " at step " << step << endl;
    }
    return 0;
}

