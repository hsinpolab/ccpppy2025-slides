
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ignore_comment_lines(ifstream &fin) {
    string line;
    while (fin.peek() == '#') getline(fin, line);
}

int chain_length[600000] = {};

int main() {
    for (int i = 0; i < 600000; ++i) {
        chain_length[i] = 1;
    }

    ifstream fin("com-amazon.ungraph.txt");
    ignore_comment_lines(fin);
    int u, v;
    while (fin >> u >> v) {
        if (chain_length[v] < chain_length[u] + 1) {
            chain_length[v] = chain_length[u] + 1;
        }
    }
    int z;
    cin >> z;
    cout << chain_length[z] << endl;
    return 0;
}

