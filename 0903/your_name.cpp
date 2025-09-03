
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    cout << "Length of your name: " << name.length() << endl;

    string word1, word2;
    cout << "Enter two words: ";
    cin >> word1 >> word2;
    cout << "You entered: " << word1 << " and " << word2 << endl;

    string combined = word1 + " and " + word2;
    cout << "Combined: " << combined << endl;

    return 0;
}
