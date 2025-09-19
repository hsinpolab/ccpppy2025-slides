
#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

string white2black =  " .:-=+*#%@";
void PrintPixel(float pvalue) {
    int pint = round(pvalue); if (pint > 9) {pint = 9;} if (pint < 0) {pint = 0;} cout << white2black[pint];
}
void InitializePhoto(float ch[50][100]) {
    for (int y = 0; y < 50; y++) { for (int x = 0; x < 100; x++) { ch[y][x]=1 + 1*sin(0.3*x-0.5*y)*sin(-0.1*x+0.05*y); } }
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
                           + (ch[y1][x] - ch[y][x])
                           + (ch[y2][x] - ch[y][x]);
            newch[y][x] = ch[y][x] + neighbor / 20;
        }
    }
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            ch[y][x] = newch[y][x];
        }
    }
}

void Reaction(float ch[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            ch[y][x] += ch[y][x] * (10 - ch[y][x]) / 100;
        }
    }
}

int main() {
    float chemical[50][100];
    float newchem[50][100];
    InitializePhoto(chemical);
    for (int repeat = 0; repeat < 10000; repeat++) {
        Diffusion(chemical, newchem);
        Reaction(chemical);
        PrintPhoto(chemical);
        usleep(100000);
    }
}
