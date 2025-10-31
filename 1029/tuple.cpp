
#include<iostream>
#include<tuple>
#include<string>
using namespace std;

int main(){
    tuple<int, float, string> Pi = {3, 3.14, "circle"};
    cout << "use get:" << endl;
    cout << get<0>(Pi) << " " << get<1>(Pi) << " " << get<2>(Pi) << endl;
    auto [a, b, c] = Pi;
    cout << "use unpacking:" << endl;
    cout << a << " " << b << " " << c << endl;
}

