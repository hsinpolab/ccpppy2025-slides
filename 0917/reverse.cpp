
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100] = {};
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = i;
    }
    int MelonCoco[100] = {};
    for (int i = 0; i < 100; i++) {
        MelonCoco[i] = CocoMelon[100 - 1 - i];
    }
    for (int i = 0; i < 100; i++) {
        cout << CocoMelon[i] << " " << MelonCoco[i] << endl;
    }
    return 0;
}
