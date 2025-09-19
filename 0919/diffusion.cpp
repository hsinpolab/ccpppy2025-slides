
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
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ph[y][x] += 100 * (rand() % 10000 == 1); } }
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

void Diffusion(float ph[50][100], float newph[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            int x1 = (x + 1 + 100) % 100; // int x1 = x + 1; if (x1 == 100) { x1 = 0; }
            int x2 = (x - 1 + 100) % 100; // int x2 = x - 1; if (x2 == -1) { x2 = 99; }
            int y1 = (y + 1 + 50) % 50;   // int y1 = y + 1; if (y1 == 50) { y1 = 0; }
            int y2 = (y - 1 + 50) % 50;   // int y2 = y - 1; if (y2 == -1) { y2 = 49; }
            float neighbor = (ph[y][x1] - ph[y][x])
                           + (ph[y][x2] - ph[y][x])
                           + (ph[y1][x] - ph[y][x])
                           + (ph[y2][x] - ph[y][x]);
            newph[y][x] = ph[y][x] + neighbor / 10;
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
        Diffusion(photo, newphoto);
        PrintPhoto(photo);
        usleep(100000);
    }
}
