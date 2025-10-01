
#include <iostream>
#include <string>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Rectangle {
    string label;
    struct Point southwest;
    struct Point northeast;
    char fill_color;
    char draw_color;
};


// typedef struct Rectangle Rec;
// Rec Shift(Rec, Vec) {return Rec} // TODO
// Rec Scale(Rec, Mul) {return Rec} // TODO
// Rec Rotate(Rec, Ang) {return Rec} // TODO

char Canvas[200][100] = {};

void Print2Canvas(Rectangle r1) {
    // Fill the rectangle
    for (int yy = r1.southwest.y; yy <= r1.northeast.y; yy++) {
        for (int xx = r1.southwest.x; xx <= r1.northeast.x; xx++) {
            Canvas[yy][xx] = r1.fill_color;
        }
    }
    // Draw the rectangle
    for (int yy = r1.southwest.y; yy <= r1.northeast.y; yy++) {
        Canvas[yy][r1.southwest.x] = r1.draw_color;
        Canvas[yy][r1.northeast.x] = r1.draw_color;
    }
    for (int xx = r1.southwest.x; xx <= r1.northeast.x; xx++) {
        Canvas[r1.southwest.y][xx] = r1.draw_color;
        Canvas[r1.northeast.y][xx] = r1.draw_color;
    }
    // Print the label
    int midx = (r1.southwest.x + r1.northeast.x) / 2;
    int midy = (r1.southwest.y + r1.northeast.y) / 2;
    int lsize = r1.label.size();
    for (int ii = 0; ii < lsize; ii++) {
        Canvas[midy][midx - lsize/2 + ii] = r1.label[ii];
    }
}

void ClearCanvas() {
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 200; x++) {
            Canvas[y][x] = ' ';
        }
    }
}

void ShowCanvas() {
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            cout << Canvas[y][x];
        }
        cout << endl;
    }
}

int main() {
    ClearCanvas();

    struct Rectangle DG;
    DG.label = "DanG2";
    DG.southwest.x = 40;
    DG.southwest.y = 40;
    DG.northeast.x = 80;
    DG.northeast.y = 60;
    DG.fill_color = '.';
    DG.draw_color = '#';
    Print2Canvas(DG);

    struct Rectangle Z2;
    Z2.label = "Zone2";
    Z2.southwest = {.x=5, .y=65};
    Z2.northeast = {.x=50, .y=90};
    Z2.fill_color = ',';
    Z2.draw_color = 'x';
    Print2Canvas(Z2);

    struct Rectangle Gl;
    Gl = {
        .label= "Glass",
        .southwest={.x=50, .y=5},
        .northeast={.x=80, .y=35},
        .fill_color='\'',
        .draw_color='@'
    };
    Print2Canvas(Gl);

    ShowCanvas();
}

