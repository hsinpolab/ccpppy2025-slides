
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

string white2black =  " .:-=+*#%@";
void PrintPixel(float pvalue) {
    int pint = round(pvalue); if (pint > 9) {pint = 9;} if (pint < 0) {pint = 0;} cout << white2black[pint];
}
void InitializePhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ph[y][x]=6*sin(0.3*x-0.5*y)*sin(-0.1*x+0.05*y); } }
}
void PrintPhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { PrintPixel(ph[y][x]); } cout << endl; }
}
void DarkerPhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ph[y][x] *= 0.9; } }
}
void AddNoise(float ph[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ph[y][x] += 20 * (rand() % 500 == 1); } }
}
void Drifting(float ph[50][100], float newph[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            newph[y][x] = ph[y][x-1];
        }
    }
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            ph[y][x] = newph[y][x-1];
        }
    }
}
int main() {
    float photo[50][100]; // This is a 2D array
    float newphoto[50][100]; // This is a temporary 2D array so that 
    // the Drifting function have additional space to work with
    InitializePhoto(photo);
    for (int repeat = 0; repeat < 100; repeat++) {
        DarkerPhoto(photo);
        AddNoise(photo);
        if (repeat % 3 == 0) { Drifting(photo, newphoto); }
        PrintPhoto(photo);
        usleep(100000);
    }
}
