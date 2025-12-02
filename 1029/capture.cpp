
#include<iostream>
using namespace std;

int main(){
    int y = 2;
    auto addy = [y](int x){ // capture y by value don't care about its later changes 
        return x + y;
    };
    cout << addy(3) << endl;
    y = 3;
    cout << addy(3) << endl;
}

