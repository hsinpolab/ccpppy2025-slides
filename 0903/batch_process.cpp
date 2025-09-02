
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("summands3.txt");
    cout << "I am opening the file summands3.txt for input" << endl;

    ofstream fout("sums3.txt");
    cout << "I am opening the file sum3.txt for output" << endl;

    cout << "I am reading two integers and summing" << endl;
    int a, b;
    fin >> a >> b;
    fout << a + b << endl;
 
    cout << "I am reading two integers and summing" << endl;   
    fin >> a >> b;
    fout << a + b << endl;

    cout << "I am reading two integers and summing" << endl;
    fin >> a >> b;
    fout << a + b << endl;

    return 0;
}
