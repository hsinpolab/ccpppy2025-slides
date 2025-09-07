
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int n = 0;
    while (true) {
        n = n + 1;
        cout << n << endl;
        sleep(1);
    }
    return 0;
}
