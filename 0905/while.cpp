
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int m = 0;
    int n = 0;
    while (true) {
        m = m + 1;
        while (true) {
            n = n + 1;
            cout << "+";
            if (m > 10) break;
        }
        cout << endl;
        if (m > 10) break;
    }
    return 0;
}
