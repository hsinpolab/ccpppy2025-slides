
#include <iostream>
using namespace std;

int main() {
    int N = 12;
    cout << "N: " << N << endl;
    cout << endl;

    int *my_first_pointer;
    my_first_pointer = &N; // pointer to N
    cout << "my_first_pointer: " << my_first_pointer << endl;
    cout << "*my_first_pointer: " << *my_first_pointer << endl;
    cout << endl;

    N = 20; // change value of N
    cout << "N = 20;" << endl;
    cout << "N: " << N << endl;
    cout << "my_first_pointer: " << my_first_pointer << endl;
    cout << "*my_first_pointer: " << *my_first_pointer << endl;
    cout << endl;

    *my_first_pointer = 28; // change value of N by pointer
    cout << "*my_first_pointer = 28;" << endl;
    cout << "N: " << N << endl;
    cout << "my_first_pointer: " << my_first_pointer << endl;
    cout << "*my_first_pointer: " << *my_first_pointer << endl;
    cout << endl;

    return 0;
}

