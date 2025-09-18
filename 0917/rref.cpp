
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float A[3][3] = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = (7 * i + 3 * j + 5) % 13;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            cout << A[i][k] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++) { // index of pivot
        for (int j = i + 1; j < 3; j++) { // index of row being eliminated
            float ratio = A[j][i] / A[i][i];
            for (int k = 0; k < 3; k++) { // index of column being eliminated
                A[j][k] -= ratio * A[i][k];
            }
        }
    }
    cout << "After gaussian elimination" << endl;
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            cout << A[i][k] << ' ';
        }
        cout << endl;
    }
    cout << "Determinant " << A[0][0] * A[1][1] * A[2][2];
    return 0;
}
