
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    char a, b, c, d, e;
    char temp;
    cin >> a >> b >> c >> d >> e;
    while (true) {
        if (a > b) { temp = a; a = b; b = temp; }
        if (b > c) { temp = b; b = c; c = temp; }
        if (c > d) { temp = c; c = d; d = temp; }
        if (d > e) { temp = d; d = e; e = temp; }
        cout << a << b << c << d << e << endl;
        if (a < b && b < c && c < d && d < e) { break; }
    }
}
