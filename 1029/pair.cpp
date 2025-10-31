
#include<iostream>
#include<string>
using namespace std;

template <typename T1>
struct Pair{
    T1 a;
    T1 b;
};

template <typename T1>
T1 Sumarray(Pair<T1> P){
    T1 a = P.a;
    T1 b = P.b;
    T1 sum = a + b;
    return sum;
}

int main(){
    Pair<int> Pi = {3, 5};
    cout << Sumarray(Pi) << endl;
    Pair<float> Pf = {2.5, 4.5};
    cout << Sumarray(Pf) << endl;
    Pair<string> Ps = {"Hello, ", "world!"};    
    cout << Sumarray(Ps) << endl;
}

