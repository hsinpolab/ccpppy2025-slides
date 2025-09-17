
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100] = {};
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = i;
    }
    int shift;
    cout << "How much do you want to shift? " << endl;
    cin >> shift;
    cout << "You want to shift by " << shift << endl;
    for (int i = 0; i < 100 / 2; i++) {
        int a = CocoMelon[i];
        int b = CocoMelon[100 - 1 - i];
        CocoMelon[i] = b;
        CocoMelon[100 - 1 - i] = a;
    }
    for (int i = 0; i < shift / 2; i++) {
        int a = CocoMelon[i];
        int b = CocoMelon[shift - 1 - i];
        CocoMelon[i] = b;
        CocoMelon[shift - 1 - i] = a;
    }
    for (int i = 0; i < (100 - shift) / 2; i++) {
        int a = CocoMelon[shift + i];
        int b = CocoMelon[100 - 1 - i];
        CocoMelon[shift + i] = b;
        CocoMelon[100 - 1 - i] = a;
    }
    for (int i = 0; i < 100; i++) {
        cout << CocoMelon[i] << " ";
    }
    return 0;
}
