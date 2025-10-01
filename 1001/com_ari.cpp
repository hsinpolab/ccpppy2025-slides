
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct ComplexNumber {
    float real_part;
    float imaginary_part;
};

string ComplexToString (struct ComplexNumber Z) {
    string result =
        to_string(Z.real_part)
        + " + "
        + to_string(Z.imaginary_part)
        + "i";
    return result;
}

struct ComplexNumber ComplexAdd(
    struct ComplexNumber Z,
    struct ComplexNumber W
) {
    struct ComplexNumber Sum;
    Sum.real_part =
        Z.real_part + W.real_part;
    Sum.imaginary_part =
        Z.imaginary_part +
        W.imaginary_part;
    return Sum;
}

int main() {
    struct ComplexNumber Zmany[100];
    Zmany[0].real_part = 1.0;
    Zmany[0].imaginary_part = 2.0;
    Zmany[0] = {1.0, 2.0};

    for (int ndx = 0; ndx < 100; ndx++) {
            // Sun flower?
            // What does this look like on the complex plane?
            // www.desmos.com/calculator/y7ojlxw0wq
            float theta = ndx * 2 * 3.14159 * (sqrt(5) - 1) / 2;
            float radius = sqrt(ndx);
            float rp = radius * cos(theta);
            float ip = radius * sin(theta);
            Zmany[ndx] = {.real_part = rp, .imaginary_part = ip};
        }
    
    for (int ndx = 0; ndx < 10; ndx++) {
        cout << ComplexToString(Zmany[ndx]) << endl;
    }
    
    return 0;
}

