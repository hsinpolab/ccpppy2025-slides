#include <iostream>
#include <array>
using namespace std;

template <typename T>
class T2x2Matrix {
public:
    T m[2][2];

    // 特徵多項式的係數(返回 pair:trace 和 determinant)
    pair<T, T> charpoly_coef() const {
        T trace = m[0][0] + m[1][1];           // tr(A)
        T det = m[0][0]*m[1][1] - m[0][1]*m[1][0]; // det(A)
        return {trace, det};
    }

    // 驗證 Cayley-Hamilton:A² - tr(A)·A + det(A)·I = 0
    T2x2Matrix cayley_hamilton() const {
        auto [trace, det] = charpoly_coef();

        T2x2Matrix A2 = (*this) * (*this);      // A²
        T2x2Matrix trA = (*this) * trace;       // tr(A)·A
        T2x2Matrix detI;                        // det(A)·I
        detI.m[0][0] = det; detI.m[0][1] = 0;
        detI.m[1][0] = 0;   detI.m[1][1] = det;

        return A2 - trA + detI;  // 應該等於 0
    }

    // 運算子重載
    T2x2Matrix operator*(const T2x2Matrix& other) const {
        T2x2Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.m[i][j] += this->m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }
    T2x2Matrix operator*(T scalar) const {
        T2x2Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m[i][j] = this->m[i][j] * scalar;
            }
        }
        return result;
    }
    T2x2Matrix operator-(const T2x2Matrix& other) const {
        T2x2Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m[i][j] = this->m[i][j] - other.m[i][j];
            }
        }
        return result;
    }
    T2x2Matrix operator+(const T2x2Matrix& other) const {
        T2x2Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.m[i][j] = this->m[i][j] + other.m[i][j];
            }
        }
        return result;
    }
};


int main() {
    T2x2Matrix<int> A;
    A.m[0][0] = 3; A.m[0][1] = 1;
    A.m[1][0] = 0; A.m[1][1] = 2;

    auto [trace, det] = A.charpoly_coef();
    cout << "特徵多項式: λ² - " << trace << "λ + " << det << endl;
    // 輸出: λ² - 5λ + 6

    auto result = A.cayley_hamilton();
    cout << "驗證 p(A) = 0:" << endl;
    cout << result.m[0][0] << " " << result.m[0][1] << endl;
    cout << result.m[1][0] << " " << result.m[1][1] << endl;
    // 輸出:0 0
    //      0 0

    return 0;
}
