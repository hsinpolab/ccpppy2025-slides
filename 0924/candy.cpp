
#include <iostream>
using namespace std;

void birthday(int c) {
    c += 1;
}

void birthday_ref(int &c) {
    c += 1;
}

void christmas(int can[100]) {
    for (int i = 0; i < 100; ++i) {
        can[i] += 1;
    }
}

int main () {
    int candy[100];
    for (int i = 0; i < 100; ++i) {
        candy[i] = i;
    }

    birthday(candy[0]);
    cout << candy[0] << endl; // still 0, but why?

    birthday_ref(candy[0]);
    cout << candy[0] << endl; // now 1, but why?

    christmas(candy);
    cout << candy[0] << endl; // now 2
}

