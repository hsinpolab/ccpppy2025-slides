
#include <iostream>
using namespace std;

int main() {
    int CocoMelon[100];
    for (int i = 0; i < 100; i++) {
        CocoMelon[i] = i;
    }
    int sum = 0;
    int min = CocoMelon[0];
    int max = CocoMelon[0];
    for (int i = 0; i < 100; i++) {
        sum += CocoMelon[i];
        if (CocoMelon[i] < min) {
            min = CocoMelon[i];
        }
        if (CocoMelon[i] > max) {
            max = CocoMelon[i];
        }
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << double(sum) / 100 << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    return 0;
}
