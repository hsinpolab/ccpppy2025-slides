
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ignore_comment_lines(ifstream &fin) {
    // Count how many lines start with '#' in a separate session
    ifstream count_hashtag("com-amazon.ungraph.txt");
    string line;
    int count = 0;
    while (getline(count_hashtag, line)) {
        if (line.empty() || line[0] != '#') {
            break;
        }
        count++;
    }
    count_hashtag.close();
    // Now skip those lines in the original file
    for (int i = 0; i < count; i++) getline(fin, line);
}

int nPaths1[600000] = {};
int nPaths2[600000] = {};
int nPaths3[600000] = {};
int nPaths4[600000] = {};
int nPaths5[600000] = {};

int main() {
    int u, v;

    // Read the graph from the file for #paths(1 -> a)
    ifstream fin1("com-amazon.ungraph.txt");
    ignore_comment_lines(fin1);
    while (fin1 >> u >> v) {
        if (u == 1) nPaths1[v] += 1;
        if (v == 1) nPaths1[u] += 1;
    }
    fin1.close();
    int a;
    cin >> a;
    cout << nPaths1[a] << " ";

    // Read the graph from the file for #paths(1 -> ? -> b)
    ifstream fin2("com-amazon.ungraph.txt");
    ignore_comment_lines(fin2);
    while (fin2 >> u >> v) {
        nPaths2[v] += nPaths1[u];
        nPaths2[u] += nPaths1[v];
    }
    fin2.close();
    int b;
    cin >> b;
    cout << nPaths2[b] << " ";

    // Read the graph from the file for #paths(1 -> ? -> ? -> c)
    ifstream fin3("com-amazon.ungraph.txt");
    ignore_comment_lines(fin3);
    while (fin3 >> u >> v) {
        nPaths3[v] += nPaths2[u];
        nPaths3[u] += nPaths2[v];
    }
    fin3.close();
    int c;
    cin >> c;
    cout << nPaths3[c] << " ";

    // Read the graph from the file for #paths(1 -> ? -> ? -> ? -> d)
    ifstream fin4("com-amazon.ungraph.txt");
    ignore_comment_lines(fin4);
    while (fin4 >> u >> v) {
        nPaths4[v] += nPaths3[u];
        nPaths4[u] += nPaths3[v];
    }
    fin4.close();
    int d;
    cin >> d;
    cout << nPaths4[d] << " ";

    // Read the graph from the file for #paths(1 -> ? -> ? -> ? -> ? -> e)
    ifstream fin5("com-amazon.ungraph.txt");
    ignore_comment_lines(fin5);
    while (fin5 >> u >> v) {
        nPaths5[v] += nPaths4[u];
        nPaths5[u] += nPaths4[v];
    }
    fin5.close();
    int e;
    cin >> e;
    cout << nPaths5[e] << endl;

    return 0;
}

