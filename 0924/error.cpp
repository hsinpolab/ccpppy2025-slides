
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    string student_id;
    cin >> student_id;
    ifstream fin(student_id + ".txt");
    if (!fin) { // check if file exists
        return 1;
    }
    if (fin.peek() == EOF) { // check if file is empty
        return 2;
    }
    char c;
    fin.get(c);
    if (c != '#') { // check if file starts with #
        return 3;
    }
    return 0;
}

