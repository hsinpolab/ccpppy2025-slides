
#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

int main() {
    mt19937 m7(20250917);
    float Arch[20] = {};
    for (int i = 0; i < 20; i++) {
        int height = i * (20 - i) + 10;
        int height_random = m7() % height;
        Arch[i] = height_random;
    }
    bool converging = false;
    while (!converging) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < Arch[i]; j++) {
                cout << ")";
            }
            cout << endl;
        }
        sleep(1);
        converging = true;
        for (int i = 1; i < 20 - 1; i++) {
            float a = Arch[i - 1];
            float b = Arch[i];
            float c = Arch[i + 1];
            if (a + c > 2 * b + 1e-2) {
                b = (a + c) / 2;
                Arch[i] = b;
                converging = false;
            }
        }
    }
    return 0;
}
