
#include <iostream>
#include <vector>
using namespace std;
const int ROWS = 10;
const int COLS = 15;

int Fins[ROWS][COLS] = {
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
};

double SimulateCpuTemperature(double g) {
    // Initialize temperature grid
    vector<vector<double>> Temper(ROWS, vector<double>(COLS, 30));
    vector<vector<double>> TemNew = Temper;
    bool still_cooling = true;
    while (still_cooling) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 1; j < COLS; ++j) {
                double tdif = Temper[i][j] - Temper[i][j-1];
                if (Fins[i][j-1] + Fins[i][j] == 1) { // fin-air
                    if (Fins[i][j-1]) TemNew[i][j-1] += tdif / 100.;
                    if (Fins[i][j]) TemNew[i][j] -= tdif / 100.;
                }
                if (Fins[i][j-1] + Fins[i][j] == 2) { // fin-fin
                    TemNew[i][j-1] += tdif / 10.;
                    TemNew[i][j] -= tdif / 10.;
                }
                if (Fins[i][j-1] + Fins[i][j] == 3) { // fin-cpu
                    TemNew[i][j-1] += tdif / 20.;
                    TemNew[i][j] -= tdif / 20.;
                }
                if (Fins[i][j-1] + Fins[i][j] == 4) { // cpu-cpu
                    TemNew[i][j-1] += tdif / 50.;
                    TemNew[i][j] -= tdif / 50.;
                }
            }
        }
        for (int i = 1; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                double tdif = Temper[i][j] - Temper[i-1][j];
                if (Fins[i-1][j] + Fins[i][j] == 1) { // fin-air
                    if (Fins[i-1][j]) TemNew[i-1][j] += tdif / 100.;
                    if (Fins[i][j]) TemNew[i][j] -= tdif / 100.;
                }
                if (Fins[i-1][j] + Fins[i][j] == 2) { // fin-fin
                    TemNew[i-1][j] += tdif / 10.;
                    TemNew[i][j] -= tdif / 10.;
                }
                if (Fins[i-1][j] + Fins[i][j] == 3) { // fin-cpu
                    TemNew[i-1][j] += tdif / 20.;
                    TemNew[i][j] -= tdif / 20.;
                }
                if (Fins[i-1][j] + Fins[i][j] == 4) { // cpu-cpu
                    TemNew[i-1][j] += tdif / 50.;
                    TemNew[i][j] -= tdif / 50.;
                }
            }
        }

        still_cooling = false;
        for (int j = 0; j < COLS; j++) {
            if (Fins[9][j] != 2) break;
            TemNew[9][j] += g;
            if (abs(TemNew[9][j] - Temper[9][j]) > 1e-6) {
                still_cooling = true;
            }
        }
        Temper = TemNew;
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << Temper[i][j] << " ";
        }
        cout << endl;
    }

    double max_cpu_temp = 30;
    for (int j = 0; j < COLS; ++j) {
        max_cpu_temp = max(max_cpu_temp, Temper[9][j]);
    }
    return max_cpu_temp;
}

int main() {
    double TestingCases[10] = {0.15, 0.25, 0.35, 0.45, 0.55, 0.65, 0.75, 0.85, 0.95, 1.05};
    // double TestingCases[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double Answers[10] = {40.4425, 47.4043, 54.366, 61.3278, 68.2896, 75.2513, 82.2131, 89.1748, 96.1366, 103.098};
    for (int ndx = 0; ndx < 10; ndx ++) {
        double g = TestingCases[ndx];
        double hottest = SimulateCpuTemperature(g);
        cout << int((hottest - Answers[ndx]) * 10000) << "/10000";
        cout << "   g: " << g << " --> Hottest: " << hottest << "\n";
    }
    return 0;
}
/*
 * 0.1 --> 42.52
 * 0.2 --> 55.0403
 * 0.3 --> 67.5607
 * 0.4 --> 80.0811
 * 0.5 --> 92.6014
 * 0.6 --> 105.122
 * 0.7 --> 117.642
 * 0.8 --> 130.163
 * 0.9 --> 142.683
 * 1.0 --> 155.203
 */
