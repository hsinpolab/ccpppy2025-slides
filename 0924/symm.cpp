
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void ignore_comment_lines(ifstream &fin) {
    string line;
    while (fin.peek() == '#') getline(fin, line);
}

int edges[2000000][2] = {};
int degree[600000] = {};
int prefix_sum[600000] = {};
int degree_so_far[600000] = {};

int main() {
    ifstream fin("com-amazon.ungraph.txt");
    ignore_comment_lines(fin);

    int u, v;
    while (fin >> u >> v) {
        degree[u]++;
        degree[v]++;
    }
    for (int i = 0; i < 600000; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + degree[i];
    }

    fin.clear(); // clear EOF flag
    fin.seekg(0); // reset to beginning
    ignore_comment_lines(fin);
    while (fin >> u >> v) {
        int pos_u = prefix_sum[u - 1] + degree_so_far[u];
        edges[pos_u][0] = u;
        edges[pos_u][1] = v;
        degree_so_far[u]++;
        int pos_v = prefix_sum[v - 1] + degree_so_far[v];
        edges[pos_v][0] = v;
        edges[pos_v][1] = u;
        degree_so_far[v]++;
    }
    fin.close();

    int n;
    cin >> n;
    cout << edges[n][0] << " " << edges[n][1] << endl;
    return 0;
}

