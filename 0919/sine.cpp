
#include <iostream>
#include <cmath>
using namespace std;

string white2black =  " .:-=+*#%@";
void PrintPixel(float pvalue) {
    int pint = round(pvalue);
    if (pint > 9) {pint = 9;} // Clamp the value
    if (pint < 0) {pint = 0;} // Clamp the value
    // https://en.wikipedia.org/wiki/Clamping_(graphics)
    cout << white2black[pint];
}

void InitializePhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            // Initialize pixels using sin
            ph[y][x] = 6 * sin(0.3*x-0.5*y) * sin(-0.1*x+0.05*y);
        }
    }
}

void PrintPhoto(float ph[50][100]) {
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            // Using the function PrintPixel to print the pixel
            PrintPixel(ph[y][x]);
        }
        cout << endl; // Go to the next row
    }
}

int main() {
    float photo[50][100]; // This is a 2D array
    InitializePhoto(photo);    
    PrintPhoto(photo);
}
