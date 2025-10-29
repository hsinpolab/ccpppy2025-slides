

#include<iostream>
using namespace std;

int main(){
    int A[10] = {0,1,2,3,4,5,6,7,8,9};
    auto square = [](int x){ return x * x; };
    for(int i = 0; i < 10; i++){
        cout << square(A[i]) << endl;
    }
}

