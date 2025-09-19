
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

string white2black =  " .:-=+*#%@";
void PrintPixel(float pvalue) {
    int pint = round(2 * pvalue + 5); if (pint > 9) {pint = 9;} if (pint < 0) {pint = 0;} cout << white2black[pint];
}
void InitializePhoto1(float ch[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ch[y][x] = 2 * sin(0.3*x-0.5*y); } }
}
void InitializePhoto2(float ch[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ch[y][x] = 2 * sin(-0.2*x+0.1*y); } }
}
void PrintPhoto(float ch[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { PrintPixel(ch[y][x]); } cout << endl; }
}

void Diffusion(float ch[50][100], float newch[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            int x1 = (x + 1 + 100) % 100; // int x1 = x + 1; if (x1 == 100) { x1 = 0; }
            int x2 = (x - 1 + 100) % 100; // int x2 = x - 1; if (x2 == -1) { x2 = 99; }
            int y1 = (y + 1 + 50) % 50;   // int y1 = y + 1; if (y1 == 50) { y1 = 0; }
            int y2 = (y - 1 + 50) % 50;   // int y2 = y - 1; if (y2 == -1) { y2 = 49; }
            float neighbor = (ch[y][x1] - ch[y][x])
                           + (ch[y][x2] - ch[y][x])
                           + (ch[y1][x] - ch[y][x]) / 2
                           + (ch[y2][x] - ch[y][x]) / 2;
            newch[y][x] = ch[y][x] + neighbor / 10;
        }
    }
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            ch[y][x] = newch[y][x];
        }
    }
}

void Reaction(float act[50][100], float inh[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            float a = act[y][x];
            float i = inh[y][x];
            act[y][x] += (a * (1 - a*a / 3) - i) / 10;
            inh[y][x] += a / 10; // Van der Pol oscillator
        }
    }
}

int main() {
    float activator[50][100];
    float inhibitor[50][100];
    float newchem[50][100];
    InitializePhoto1(activator);
    InitializePhoto2(inhibitor);
    for (int repeat = 0; repeat < 10000; repeat++) {
        Diffusion(activator, newchem);
        Diffusion(inhibitor, newchem);
        Reaction(activator, inhibitor);
        PrintPhoto(activator);
        usleep(100000);
    }
}
