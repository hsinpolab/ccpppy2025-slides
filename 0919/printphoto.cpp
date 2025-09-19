

#include <iostream>
#include <cmath>
using namespace std;

string white2black =  " .:-=+*#%@";
// The names of these characters:
//  space
// .period
// :colon
// -hyphen
// =equal
// +plus
// *asterisk
// #hash
// %percent
// @at

// 0 is white, 3 is light gray, 6 is dark gray, 9 is black
void PrintPixel(float pvalue) {
    // void means this function does not return anything
    int pint = round(pvalue);
    if (pint > 9) {pint = 9;} // Clamp the value
    if (pint < 0) {pint = 0;} // Clamp the value
    // https://en.wikipedia.org/wiki/Clamping_(graphics)
    cout << white2black[pint];
    // instead of cout-ing the number pint,
    // we cout character that requires more ink to represent higher number

    // As mentioned, void means this function does not return anything
    // So we don't write a return statement here
}

int main() {
    float photo[50][100]; // This is a 2D array
    // Height is 50, width is 100
    // photo is the entire photo
    // photo[0] is the first row
    // photo[0][0] is the first pixel of the first row
    // etc etc
    // photo[49][99] is the last pixel of the last row
    // Try cout << photo, what do you get?
    // Try cout << photo[0], what do you get?

    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            // Initialize every pixel as a random number between 0 and 9
            photo[y][x] = rand() % 10;
            // photo[y][x]=6*sin(0.3*x-0.5*y)*sin(-0.1*x+0.05*y);
        }
    }
    
    for (int y = 0; y < 50; y++) {
        for (int x = 0; x < 100; x++) {
            // Using the function PrintPixel to print the pixel
            PrintPixel(photo[y][x]);
        }
        cout << endl; // Go to the next row
    }
}
