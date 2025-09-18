
#include <iostream>
#include <random>
using namespace std;

int main() {
    mt19937 m7(20250917);
    int Votes[5] = {};
    for (int i = 0; i < 100; i++) {
        int vote = m7() % 5;
        Votes[vote]++;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Candidate " << i
        << " received " << Votes[i] << " votes." << endl;
    }
    return 0;
}
