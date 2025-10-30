
#include<iostream>
#include <typeinfo>
using namespace std;

int main(){
    auto add2 = [](int x){ return x + 2; };
    cout << typeid(add2).name() << endl;
    cout << add2(3) << endl;
    auto add2_ = [](int x){ return x * 10 + 2; };
    cout << add2_(3) << endl;
}

