
#include<iostream>
#include<string>
using namespace std;

template <typename T1>
T1 Pair(T1 a, T1 b){
    return make_pair(a, b);
}

int main(){
    int A[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << Sumarray(A, 10, 0) << endl;
    double B[5] = {0.1,0.2,0.3,0.4,0.5};
    cout << Sumarray(B, 5, 0.0) << endl;
    string S[3] = {"Hello, ", "world", "!"};
    cout << Sumarray(S, 3, string("")) << endl;
}

