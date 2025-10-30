
#include<iostream>
using namespace std;

void arrayapply(int A[], int n, auto func){
    for(int i = 0; i < n; i++){
        cout << func(A[i]) << endl;
    }
}

int main(){
    int A[10] = {0,1,2,3,4,5,6,7,8,9};
    auto square = [](int x){ return x * x; };
    auto cube = [](int x){ return x * x * x; };
    arrayapply(A, 10, square);
    arrayapply(A, 10, cube);
}

