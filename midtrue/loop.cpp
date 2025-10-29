
#include <iostream>
#include <random>
using namespace std;

int main() {
    int S = 0;
    for (int i = 0; i < 100000000; i++) {
        if (rand() % 17) { S++; }
    }
}

