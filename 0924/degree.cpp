
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("com-amazon.ungraph.txt");
    if (!fin) { // check if file can be opened
        cerr << "Cannot open file." << endl;
        return 1;
    }

    string line;
    getline(fin, line);
    getline(fin, line);
    getline(fin, line);
    getline(fin, line); // ignore first four lines

    int v, a, b;
    cin >> v;
    int degree = 0;
    while (fin >> a >> b) {
        if (a == v || b == v) degree++;
    }
    cout << degree << endl;
    return 0;
}

