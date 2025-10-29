
#include <iostream>
using namespace std;

float i(float x) { return 10 * x + 1; }
float i(int x) { return 10 * x + 2; }
int f(float x) { return 10 * x + 3; }
int f(int x) { return 10 * x + 4; }

int main() {
    cout << f(f(i(5))) << endl;
    cout << f(f(i(i(f(f(i(5.f))))))) << endl;
}

