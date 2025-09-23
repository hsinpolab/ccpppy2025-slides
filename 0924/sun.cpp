
#include <iostream>
using namespace std;

int temperature;
void sun_shine() {
    temperature++;
}

int main () {
    temperature = 0;
    sun_shine();
    cout << temperature << endl;
    sun_shine();
    cout << temperature << endl;
    sun_shine();
    cout << temperature << endl;
    sun_shine();
    cout << temperature << endl;

}

