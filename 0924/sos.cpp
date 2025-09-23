
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int a = -sqrt(n); a<= sqrt(n); ++a) {
        int m = n - a * a;
        for (int b = -sqrt(m); b <= sqrt(m); ++b) {
            int l = m - b * b;
            for (int c = -sqrt(l); c <= sqrt(l); ++c) {
                int k = l - c * c;
                for (int d = -sqrt(k); d <= sqrt(k); ++d) {
                    if (d * d == k) {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}

