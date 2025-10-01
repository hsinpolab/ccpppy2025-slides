
#include <iostream>
using namespace std;

struct IntOrError {
    bool isError;
    int value;
    string why;
};

string ToString (struct IntOrError a) {
    if (a.isError) {
        return "Error: " + a.why;
    }
    return to_string(a.value);
}

struct IntStack100 {
    int maxsize = 100;
    struct IntOrError content[100];
    int top; // top of the stack = how many elements are in the stack
};

void StackPush(struct IntStack100 &IS, IntOrError new_value) {
    if (IS.top == IS.maxsize) {
        cout << "Stack overflow!" << endl;
        cout << "That is, the stack reached its maximum capacity" << endl;
        cout << "so you cannot push any more elements" << endl;
        return;
    }
    IS.content[IS.top] = new_value;
    IS.top += 1;
}

IntOrError StackPop(struct IntStack100 &IS) {
    if (IS.top == 0) {
        cout << "Stack underflow!" << endl;
        // TODO use a struct that allows error codes
        IntOrError ohno = {true, -404, "Stack underflow"};
        return ohno;
    }
    IS.top--;
    return IS.content[IS.top];
}

int main() {
    struct IntStack100 PiggyBank;
    PiggyBank.top = 0;

    for (int day = 0; day < 100; day++) {
        if (rand() % 2 == 0) { // good day; save money
            IntOrError kids = {false, 1000, ""};
            StackPush(PiggyBank, kids);
            cout << "Saved $1000, balance = " << PiggyBank.top << "k" << endl;
        }
        else { // bad day; spend money
            IntOrError emergency_fund = StackPop(PiggyBank);
            cout << "Spent " << ToString(emergency_fund) << endl;
        }
    }

    return 0;
}

