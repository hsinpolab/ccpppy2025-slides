
#include <iostream>
#include <cmath>
using namespace std;

enum ErrorCode {
    DIVISION_BY_ZERO,
    SQUARE_ROOT_NEGATIVE,
    LOG_ZERO,
    LOG_NEGATIVE,
    NO_MORE_ROOTS,
};

union FloatOrError_help {
    float f;
    ErrorCode why;
};

struct FloatOrError {
    bool isError;
    FloatOrError_help value;
    // if isError is true,
    // value.why is the reason
    // if isError is false, 
    // value.f is the float value
};

string ToString(struct FloatOrError a) {
    if (!a.isError) {
        return to_string(a.value.f);
    }
    ErrorCode ecode = a.value.why;
    switch (ecode) {
        case DIVISION_BY_ZERO:
            return "Error: Division by zero";
        case SQUARE_ROOT_NEGATIVE:
            return "Error: Square root of negative number";
        case LOG_ZERO:
            return "Error: Logarithm of zero";
        case LOG_NEGATIVE:
            return "Error: Logarithm of negative number";
        case NO_MORE_ROOTS:
            return "Error: No more roots";
    }
}

struct FloatOrError sqrt(struct FloatOrError a) {
    if (a.isError) {
        return a;
    }
    if (a.value.f < 0) {
        struct FloatOrError noneg;
        noneg.isError = true;
        noneg.value.why = SQUARE_ROOT_NEGATIVE;
        return noneg; // Return the error message
    }
    struct FloatOrError result;
    result.isError = false;
    result.value.f = sqrt(a.value.f);
    return result; // Return the square root value
}

int main() {
    struct FloatOrError a = {.isError = false, .value = {.f = 2}};
    struct FloatOrError b = sqrt(a);
    cout << "square root of " << ToString(a) << " is " << ToString(b) << endl;

    struct FloatOrError c = {.isError = false, .value = {.f = -1}};
    struct FloatOrError d = sqrt(c);
    cout << "square root of " << ToString(c) << " is " << ToString(d) << endl;
}


