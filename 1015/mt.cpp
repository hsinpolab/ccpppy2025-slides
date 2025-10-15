
#include <iostream>
#include <random>
using namespace std;
int main () {
    mt19937 rand(20251015), rane(20251015), ranf(20251015);
    cout << rand() << " " << rand() << " " << rand() << endl;
    cout << rane() % 2 << endl;
    cout << ranf() % 3 << endl;
    cout << rane() % 2 << rane() % 2 << endl;
    cout << ranf() % 3 << ranf() % 3 << endl;
}

