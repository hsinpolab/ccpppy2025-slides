

#include<iostream>

using namespace std;


int main(){
    auto addtwo = [](int x){ return x + 2; };
    cout << addtwo(3) << "\n";
    auto addtwo = [](int x){ return x * 10 + 2; };
    cout << addtwo(3) << "\n";
    return 0;
}

