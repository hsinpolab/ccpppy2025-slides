
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100];
    for (int i = 0; i < 10; i++) {
        int k = i*i;
        cout << "Without initialization, the "
        << k << "th element of CocoMelon is "
        << CocoMelon[i] << endl;
    }
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        int k = i*i;
        cout << "With initialization, the "
        << k << "th element of CocoMelon is "
        << CocoMelon[i] << endl;
    }
    return 0;
}
