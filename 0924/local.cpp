
#include <iostream>
using namespace std;

void sun_shine() {
    cout << earth_rotation << endl; // error: earth_rotation is not defined here
}

int main () {
    int earth_rotation = 1;
    sun_shine();
    cout << earth_rotation << endl;
}

