
#include <iostream>
using namespace std;

int main() {
    float radius = 5.606;
    int count = 0;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            for (int k = -radius; k <= radius; k ++) {
                if (i * i + j * j + k * k < radius * radius) {
                    cout << "+";
                    count++;
                }
                else {
                    cout << ".";
                }
            }
            cout << "  ";
        }
        cout << endl;
    }
    cout << "Our estimate of pi is" << endl;
    cout << 3/4. * count / (radius * radius * radius) << endl;
    return 0;
}
