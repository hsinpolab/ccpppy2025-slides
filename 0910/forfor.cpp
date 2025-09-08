
#include <iostream>
using namespace std;

int main() {
    int radius = 10;
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            for (int k = 0; k < radius; k ++) {
                if (i * i + j * j + k * k < radius) {
                    cout << "+";
                }
                else {
                    cout << ".";
                }
            }
            cout << "  "
        }
        cout << endl;
    }
    return 0;
}
