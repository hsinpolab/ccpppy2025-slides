
#include <iostream>
using namespace std;

int main() {
    int Primes[100] = {};
    int n_prime = 0;
    for (int n = 2; n < 10000000; n++) {
        bool is_prime = true;
        for (int i = 0; i < n_prime; i++) {
            if (n % Primes[i] == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            Primes[n_prime] = n;
            n_prime++;
        }
    }
    for (int k = 0; k < 100; k++) {
        cout << Primes[k] << ' ';
    }
    return 0;
}
