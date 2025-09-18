
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100] = {};
    int PrefixSum[100] = {};
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = i;
    }
    PrefixSum[0] = 0; // is this line necessary?
    for (int i = 1; i < 100; i++) {
        PrefixSum[i] = PrefixSum[i-1] + CocoMelon[i];
    }
    for (int i = 0; i < 11; i++) {
        cout << "the " << i << "th prefix sum is "
        << PrefixSum[i] << endl;
    }
    return 0;
}
