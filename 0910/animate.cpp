
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    float f = 0;
    float df = 1;
    float dt = 1e-1;
    for (float t = 0; t < 10; t += dt) {
        float ddf = -f;
        df += ddf * dt;
        f += df * dt;

        // Now we start printing
        for (int x = -80; x <= 80; x++) {
            char c = ' ';
            int F = f * 50;
            if (x == 0) c = '|';
            if (x == F) c = '@';
            if (0 < x && x < F) c = '~';
            if (F < x && x < 0) c = '~';
            cout << c;
        }
        cout << endl;
        for (int x = -80; x <= 80; x++) {
            char c = ' ';
            int F = f * 50;
            int dF = df * 20;
            if (0 < x - F && x - F < dF) c = '>';
            if (dF < x - F && x - F < 0) c = '<';
            cout << c;
        }
        cout << endl;
        usleep(100000);
    }
    return 0;
}
