
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    for (int i = 0; i < 20; i++) {
        cout << i << endl;
        sleep(1);
    }
    return 0;
}
