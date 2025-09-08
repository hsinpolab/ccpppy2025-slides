
#include <iostream>
using namespace std;

int main() {
    for (int n = 0; n < 100; n++) {
        for (int d = 31; d >=0; d--) {
            cout << ((n >> d) & 1);
        }
        cout << endl;
    }
}
