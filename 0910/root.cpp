
#include <iostream>
using namespace std;

int main() {
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (i * i * i >= n) {
            r = i;
            break;
        }
    }
    cout << "The least number such that r^3 >= n is " << r << endl;
    cout << "To double check, notice that (r - 1)^3 = " << (r - 1) * (r - 1) * (r - 1)
    << ", n = " << n << ", and r^3 = " << r * r * r << endl;
    return 0;
}
