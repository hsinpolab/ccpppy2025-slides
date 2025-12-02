
#include <iostream>
#include <random>
using namespace std;
int main () {
    mt19937 rand(20251022), rane(20251022), ranf(20251022);
    cout << rand() << " " << rand() << " " << rand() << endl;
    cout << rane() % 16 << endl;
    cout << ranf() % 16 << endl;
    cout << rane() * ranf() % 16 << endl;
    cout << ranf() * rane() % 16 << endl;
}

