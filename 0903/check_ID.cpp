
#include <iostream>
#include <string>
using namespace std;

int main() {
    string id;
    cout << "Enter your National ID: ";
    cin >> id;

    // For the first character
    // A is ASCII 65, but should be 10 when checking
    // B is ASCII 66, but should be 11 when checking
    // C is ASCII 67, but should be 12 when checking
    // etc

    int letter = (id[0] % 32) + 9;
    int letter10 = letter / 10;
    int letter1 = letter % 10;

    // For the numbers
    // 0 is ASCII 48, but should be 0 when checking
    // 1 is ASCII 49, but should be 1 when checking
    // 2 is ASCII 50, but should be 2 when checking
    // etc

    int gender = id[1] - 48;
    int num1 = id[2] - 48;
    int num2 = id[3] - 48;
    int num3 = id[4] - 48;
    int num4 = id[5] - 48;
    int num5 = id[6] - 48;
    int num6 = id[7] - 48;
    int num7 = id[8] - 48;

    int check = id[9] - 48;

    int checksum =
        + 1 * letter10
        + 9 * letter1
        + 8 * gender
        + 7 * num1
        + 6 * num2
        + 5 * num3
        + 4 * num4
        + 3 * num5
        + 2 * num6
        + 1 * num7;
    
    if ((checksum + check) % 10 == 0) {
        cout << "correct national ID" << endl;
    }
    else {
        cout << "WRONG!" << endl;
    }

    return 0;
}
