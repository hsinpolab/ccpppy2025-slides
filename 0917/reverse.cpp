
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
    for (; shift; shift--) {
        int temp = CocoMelon[0];
        for (int i = 0; i < 100 - 1; i++) {
            CocoMelon[i] = CocoMelon[i + 1];
        }
        CocoMelon[99] = temp;
    }
    for (int i = 0; i < 100; i++) {
        cout << CocoMelon[i] << " ";
    }
    return 0;
}
