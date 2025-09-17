
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100];
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = (i * 37 + 50) % 100;
        cout << CocoMelon[i] << " ";
    }
    cout << endl;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < 99; i++) {
            if (CocoMelon[i] > CocoMelon[i + 1]) {
                int a = CocoMelon[i];
                int b = CocoMelon[i + 1];
                CocoMelon[i] = b;
                CocoMelon[i + 1] = a;
                sorted = false;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        cout << CocoMelon[i] << " ";
    }
    return 0;
}
