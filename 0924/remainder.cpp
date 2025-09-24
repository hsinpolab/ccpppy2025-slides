
#include <iostream>
#include <string>
using namespace std;

bool check_congruent(int x, int m, int r) {
    return x % m == r;
}

int main() {
    // read the input
    string varname, percent, equalsign;
    int m1, r1, m2, r2, x;
    cin >> varname >> percent >> m1 >> equalsign >> r1;
    cin >> varname >> percent >> m2 >> equalsign >> r2;

    // try all numbers
    for (x = 0; ; x++) {
        if (check_congruent(x, m1, r1) && check_congruent(x, m2, r2)) {
            break;
        }
        cout << " not " << x;
        if (x % 10 == 9) cout << endl;
    }

    cout << endl;
    cout << "x = " << x << endl;
    return 0;
}

