
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ignore_comment_lines(ifstream &fin) {
    // ignore the first four lines (if we know it's four)
    string line;
    getline(fin, line);
    getline(fin, line);
    getline(fin, line);
    getline(fin, line);
}

int main() {
    ifstream fin("com-amazon.ungraph.txt");
    ignore_comment_lines(fin);

    int v, a, b;
    int degree = 0;
    cin >> v;
    while (fin >> a >> b) if (a == v || b == v) degree++;
    cout << degree << endl;

    return 0;
}

