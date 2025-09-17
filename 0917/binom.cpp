
#include <iostream>
using namespace std;

int main() {
    int Pascal[20][20] = {};
    for (int n = 0; n < 20; n++) {
        for (int k = 0; k <= n; k++) {
            if (k == 0 || k == n) {
                Pascal[n][k] = 1;
            } else {
                Pascal[n][k] = Pascal[n-1][k-1] + Pascal[n-1][k];
            }
        }
    }
    for (int a = 0; a < 20; a++) {
        for (int b = 0; b <= a; b++) {
            cout << Pascal[a][b] << ' ';
        }
        cout << endl;
    }
    return 0;
}
