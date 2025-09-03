
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double angle_deg = 30.0;
    double angle_rad = angle_deg * M_PI / 180.0;

    cout << "sin(" << angle_deg << " deg) = " << sin(angle_rad) << endl;
    cout << "cos(" << angle_deg << " deg) = " << cos(angle_rad) << endl;
    cout << "for ref, sqrt(3) / 2 is " << sqrt(3) / 2 << endl;

    angle_deg = 60.0;
    angle_rad = angle_deg * M_PI / 180.0;

    cout << "sin(" << angle_deg << " deg) = " << sin(angle_rad) << endl;
    cout << "cos(" << angle_deg << " deg) = " << cos(angle_rad) << endl;

    return 0;
}
