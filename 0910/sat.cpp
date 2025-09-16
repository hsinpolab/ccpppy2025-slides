
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Please input a permutation of ABCD such that" << endl;
    cout << "A is to the right of B" << endl;
    cout << "B is next to C" << endl;
    cout << "C is not next to D" << endl;
    cout << "D is not next to A" << endl;
    string guess;
    while (true) {
        cin >> guess;
        cout << "Your guess is " << guess << endl;
        if (guess.size() != 4) {
            cout << "Not a permutation of ABCD.  Try again." << endl;
            continue;
        }
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        for (int i = 0; i < 4; i++) {
            if (guess[i] == 'A') a++; 
            if (guess[i] == 'B') b++; 
            if (guess[i] == 'C') c++; 
            if (guess[i] == 'D') d++; 
        }
        if (a * b * c * d != 1) {
            cout << "Not a permutation of ABCD.  Try again." << endl;
            continue;
        }
        bool flag = false;
        a = b = c = d;
        for (int i = 0; i < 4; i++) {
            if (guess[i] == 'A') a++; 
            if (guess[i] == 'B') b++; 
            if (guess[i] == 'C') c++; 
            if (guess[i] == 'D') d++; 
            if (a > b) {
                flag = true;
            }
        }
        if (flag) {
            cout << "A is not to the right of B.  Try again." << endl;
            continue;
        }
        flag = true;
        for (int i = 0; i < 3; i++) {
            if (guess[i] == 'B' || guess[i] == 'C') {
                if (guess[i+1] == 'B' || guess[i+1] == 'C') {
                    flag = false;
                }
            }
        }
        if (flag) {
            cout << "B is not next to C.  Try again." << endl;
            continue;
        }
        flag = false;
        for (int i = 0; i < 3; i++) {
            if (guess[i] == 'C' || guess[i] == 'D') {
                if (guess[i+1] == 'C' || guess[i+1] == 'D') {
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << "C is next to D.  Try again." << endl;
            continue;
        }
        flag = false;
        for (int i = 0; i < 3; i++) {
            if (guess[i] == 'D' || guess[i] == 'A') {
                if (guess[i+1] == 'D' || guess[i+1] == 'A') {
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << "D is next to A.  Try again." << endl;
            continue;
        }
        cout << "It seems you succeed.  Nice!" << endl;
        break;
    }
    return 0;
}
