
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

string white2black =  " .:-=+*#%@";
void PrintPixel(float pvalue) {
    int pint = round(pvalue); if (pint > 9) {pint = 9;} if (pint < 0) {pint = 0;} cout << white2black[pint];
}
void InitializePhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ph[y][x] = 5 * (rand() % 2); } }
}
void PrintPhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { PrintPixel(ph[y][x]); } cout << endl; }
}
void BiasedFlipOne(float ph[50][100]) {
    int y = rand() % 50;
    int x = rand() % 100;
    int x1 = (x + 1 + 100) % 100; // int x1 = x + 1; if (x1 == 100) { x1 = 0; }
    int x2 = (x - 1 + 100) % 100; // int x2 = x - 1; if (x2 == -1) { x2 = 99; }
    int y1 = (y + 1 + 50) % 50;   // int y1 = y + 1; if (y1 == 50) { y1 = 0; }
    int y2 = (y - 1 + 50) % 50;   // int y2 = y - 1; if (y2 == -1) { y2 = 49; }
    float hamilton = ph[y][x1] + ph[y][x2] + ph[y1][x] + ph[y2][x];
    hamilton = hamilton / 5 * 2 - 4;
    float probability = pow(2, hamilton) / (pow(2, hamilton) + pow(2, -hamilton));
    if (rand() / float(RAND_MAX) < probability) { ph[y][x] = 5; }
    else { ph[y][x] = 0; }
}

int main() {
    float magnet[50][100];
    InitializePhoto(magnet);
    for (int repeat = 0; repeat < 1000; repeat++) {
        BiasedFlipOne(magnet);
        PrintPhoto(magnet);
        usleep(10000);
    }
}
