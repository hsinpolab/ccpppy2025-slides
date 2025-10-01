
#include <iostream>
using namespace std;

int main() {
    int N = 12;
    cout << "N = " << N << endl;
    cout << endl;

    int *pointer1;
    int *pointer2;
    int *pointer3;
    pointer1 = &N; // pointer1 points to N
    pointer2 = &N; // pointer2 also points to N
    pointer3 = &N; // pointer3 is again pointing to N

    cout << "N: " << N << endl;
    cout << "pointer1: " << pointer1 << endl;
    cout << "pointer2: " << pointer2 << endl;
    cout << "pointer3: " << pointer3 << endl;
    cout << "*pointer1: " << *pointer1 << endl;
    cout << "*pointer2: " << *pointer2 << endl;
    cout << "*pointer3: " << *pointer3 << endl;
    cout << endl;

    N = 20; // change value of N
    cout << "N = 20;" << endl;
    cout << "N: " << N << endl;
    cout << "pointer1: " << pointer1 << endl;
    cout << "pointer2: " << pointer2 << endl;
    cout << "pointer3: " << pointer3 << endl;
    cout << "*pointer1: " << *pointer1 << endl;
    cout << "*pointer2: " << *pointer2 << endl;
    cout << "*pointer3: " << *pointer3 << endl;
    cout << endl;

    *pointer1 = 28; // change value by pointer
    cout << "*pointer1 = 28;" << endl;
    cout << "N: " << N << endl;
    cout << "pointer1: " << pointer1 << endl;
    cout << "pointer2: " << pointer2 << endl;
    cout << "pointer3: " << pointer3 << endl;
    cout << "*pointer1: " << *pointer1 << endl;
    cout << "*pointer2: " << *pointer2 << endl;
    cout << "*pointer3: " << *pointer3 << endl;
    cout << endl;

    *pointer2 += 2; // change value by pointer
    cout << "*pointer2 += 2;" << endl;
    cout << "N: " << N << endl;
    cout << "pointer1: " << pointer1 << endl;
    cout << "pointer2: " << pointer2 << endl;
    cout << "pointer3: " << pointer3 << endl;
    cout << "*pointer1: " << *pointer1 << endl;
    cout << "*pointer2: " << *pointer2 << endl;
    cout << "*pointer3: " << *pointer3 << endl;
    cout << endl;

    *pointer3 = *pointer1 * *pointer2; // change value by pointer
    cout << "*pointer3 = *pointer1 * *pointer2;" << endl;
    cout << "N: " << N << endl;
    cout << "pointer1: " << pointer1 << endl;
    cout << "pointer2: " << pointer2 << endl;
    cout << "pointer3: " << pointer3 << endl;
    cout << "*pointer1: " << *pointer1 << endl;
    cout << "*pointer2: " << *pointer2 << endl;
    cout << "*pointer3: " << *pointer3 << endl;
    cout << endl;
}

