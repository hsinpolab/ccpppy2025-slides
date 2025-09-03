
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("summands.txt"); // fin = f + in = file + input
    cout << "I am opening the file summands.txt" << endl;

    cout << "I am reading two integers" << endl;
    int a, b;
    fin >> a >> b; // cin >> a >> b;

    cout << "I am printing what is read" << endl;
    cout << a << " " << b << endl;

    cout << "I am trying to sum them" << endl;
    cout << a + b << endl;

    return 0;
}
