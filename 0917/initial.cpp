
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[10] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 10; i++) {
        cout << "With initialization, the "
        << i << "th element of CocoMelon is "
        << CocoMelon[i] << endl;
    }
    return 0;
}
