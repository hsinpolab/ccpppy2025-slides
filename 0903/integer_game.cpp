
#include <iostream>
using namespace std;

int main() {
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    cout << "Is a a prime? " << a << endl;
    cout << "Is b a power of 2? " << b << endl;
    cout << "Is c a perfect square? " << c << endl;
    cout << "Is b - a even? " << b - a << endl;
    cout << "Is c + 4a^2 also a square? " << c + 4 * a * a << endl;
    cout << "Is the last digit of c equal to a? " << c % 10 - a << endl;
    return 0;
}
