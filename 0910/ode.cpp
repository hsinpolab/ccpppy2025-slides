
#include <iostream>
using namespace std;

int main() {
    float f = 0;
    float dfdt = 1;
    float dt = 1e-3;
    for (float t = 0; t < 10; t += dt) {
        float ddfddt = -f;
        dfdt += ddfddt * dt;
        f += dfdt * dt;
    }
    cout << "At t = 10" << endl;
    cout << "f(t) = " << f << endl;
    cout << "f'(t) = " << dfdt << endl;
    return 0;
}
