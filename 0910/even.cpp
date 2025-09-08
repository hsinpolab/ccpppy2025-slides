
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    int n = 0;
    while (true) {
        cout << "Please input an even number: ";
        cin >> n;
        sleep(1);
        cout << "Your input is " << n << endl;
        sleep(1);
        cout << "Thinking ..." << endl;
        sleep(1);
        cout << "It is really hard to tell ..." << endl;
        sleep(1);
        cout << "I have never seen this number before ..." << endl;
        sleep(1);
        cout << "It it taking longer than I expected ..." << endl;
        sleep(1);
        if (n % 2 == 1) {
            cout << "It is not an even number" << endl;
        }
        if (n % 2 == 0) {
            cout << "It is an even number" << endl;
            break;
        }
    }
    return 0;
}
