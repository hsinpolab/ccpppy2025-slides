
#include<iostream>
#include<tuple>
#include<string>
using namespace std;

int main(){
    pair<int, int> Pi = {3, 5};
    auto [a, b] = Pi;
    cout << "use first and second:" << endl;
    cout << Pi.first << " " << Pi.second << endl;
    cout << "use unpacking:" << endl;
    cout << a << " " << b << endl;

    pair<float, string> Pfs = {2.5, "world"};
    cout << "use first and second:" << endl;
    cout << Pfs.first << " " << Pfs.second << endl;
    cout << "use unpacking:" << endl;
    auto [x, s] = Pfs;
    cout << x << " " << s << endl;
}

