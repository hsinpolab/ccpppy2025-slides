
#include<iostream>
#include<cmath>
using namespace std;

double factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

int main () {
    auto c1 = clock();
    for (int trial = 0; trial < 1e7; trial++) {
        int n = rand() % 100;
        factorial(n);
    }
    auto c2 = clock();
    float sec = (c2 - c1) / (float)CLOCKS_PER_SEC;
    cout << "Our own factorial took " << sec << " seconds." << endl;

    c1 = clock();
    for (int trial = 0; trial < 1e7; trial++) {
        int n = rand() % 100;
        tgamma(n + 1);
    }
    c2 = clock();
    sec = (c2 - c1) / (float)CLOCKS_PER_SEC;
    cout << "Built-in factorial took " << sec << " seconds." << endl;

    return 0;
}

