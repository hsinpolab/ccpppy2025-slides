
#include <iostream>
using namespace std;

int main() {
    for (int n = 0; n < 100; n++) {
        for (int d = 31; d >=0; d--) {
            if (n - (n & (n - 1)) == 1 << d) cout << '|';
            else cout << ' ';
        }
        cout << endl;
        int m = n ^ (n >> 1);
        for (int d = 31; d >=0; d--) {
            cout << ((m >> d) & 1);
        }
        cout << "  " << m << endl;
    }
}
