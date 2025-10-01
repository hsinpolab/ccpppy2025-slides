
#include <iostream>
#include <string>
using namespace std;

struct ComplexNumber {
    float real_part;
    float imaginary_part;
};

void PrintComplex (struct ComplexNumber Z) {
    cout << Z.real_part
         << " + "
         << Z.imaginary_part
         << "i"
         << endl;
}

string ComplexToString (struct ComplexNumber Z) {
    string result =
        to_string(Z.real_part)
        + " + "
        + to_string(Z.imaginary_part)
        + "i";
    return result;
}

int main() {
    struct ComplexNumber Z1;
    Z1.real_part = 1.0;
    Z1.imaginary_part = 2.0;
    cout << "Z1 is " << ComplexToString(Z1);
    
    return 0;
}

