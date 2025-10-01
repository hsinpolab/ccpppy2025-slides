#include <iostream>
#include <cmath>
using namespace std;

struct FloatOrError {
    bool isError;
    float value;
    string why;
};

typedef struct FloatOrError stFOE;

string ToString(stFOE a) {
    if (a.isError) {
        return "Error: " + a.why;
    }
    return to_string(a.value);
}

stFOE add(stFOE a, stFOE b) {
    if (a.isError) { return a; }
    if (b.isError) { return b; }
    stFOE answer = {
        .isError = false,
        .value = a.value + b.value,
        .why = ""
    };
    return answer;
}

stFOE subtract(stFOE a, stFOE b) {
    if (a.isError) { return a; }
    if (b.isError) { return b; }
    stFOE answer = {
        .isError = false,
        .value = a.value - b.value,
        .why = ""
    };
    return answer;
}

stFOE multiply(stFOE a, stFOE b) {
    if (a.isError) { return a; }
    if (b.isError) { return b; }
    stFOE answer = {
        .isError = false,
        .value = a.value * b.value,
        .why = ""
    };
    return answer;
}

stFOE divide(stFOE a, stFOE b) {
    if (a.isError) { return a; }
    if (b.isError) { return b; }
    if (b.value == 0) {
        stFOE answer = {
            .isError = true,
            .value = 0,
            .why = "Division by zero"
        };
        return answer;
    }
    stFOE answer = {
        .isError = false,
        .value = a.value / b.value,
        .why = ""
    };
    return answer;
}

stFOE sqrt(stFOE a) {
    if (a.isError) {
        return a;
    }
    if (a.value < 0) {
        stFOE answer = {
            .isError = true,
            .value = 0,
            .why = "Square root of negative number"
        };
        return answer;
    }
    stFOE answer = {
        .isError = false,
        .value = sqrt(a.value),
        .why = ""
    };
    return answer;
}

stFOE log(stFOE a) {
    if (a.isError) {
        return a;
    }
    if (a.value <= 0) {
        stFOE answer = {
            .isError = true,
            .value = 0,
            .why = "Logarithm of zero"
                   "or negative number"
        };
        return answer;
    }
    stFOE answer = {
        .isError = false,
        .value = log(a.value),
        .why = ""
    };
    return answer;
}

void SolveQuadratic(
    stFOE a,
    stFOE b,
    stFOE c,
    stFOE roots[2]
) {
    if (a.isError) { roots[0] = roots[1] = a; return; }
    if (b.isError) { roots[0] = roots[1] = b; return; }
    if (c.isError) { roots[0] = roots[1] = c; return; }
    if (a.value == 0) {
        // linear equation bx + c = 0
        stFOE root = divide(c, b);
        if (b.value == 0) {
            // Ok it's not even linear
            if (c.value == 0) {
                root.why = "a = b = c = 0, so infinitely many roots";
            } else {
                root.why = "a = b = 0 != c, so no roots";
            }
        }
        roots[0] = root;
        roots[1] = {
            .isError = true,
            .value = 0,
            .why = "No more roots because a == 0"
        };
        return;
    }
    stFOE b2 = multiply(b, b);
    stFOE ac = multiply(a, c);
    stFOE fourac = multiply(ac, {false, 4, ""});
    stFOE b2_4ac = subtract(b2, fourac);
    stFOE sqrt_b2_4ac = sqrt(b2_4ac);
    stFOE twoa = multiply(a, {false, 2, ""});
    stFOE b_plus_sqrt = add(b, sqrt_b2_4ac);
    stFOE b_minus_sqrt = subtract(b, sqrt_b2_4ac);
    stFOE root1 = divide(b_plus_sqrt, twoa);
    stFOE root2 = divide(b_minus_sqrt, twoa);
    roots[0] = root1;
    roots[1] = root2;
}

int main() {
    stFOE a = {false, 5, ""};
    stFOE b = {false, 12, ""};
    stFOE c = {false, 4, ""};
    stFOE roots[2];
    SolveQuadratic(a, b, c, roots);
    cout << "Roots are "
         << ToString(roots[0])
         << " and "
         << ToString(roots[1])
         << endl;

    stFOE bb = {false, 2, ""};
    SolveQuadratic(a, bb, c, roots);
    cout << "Roots are "
         << ToString(roots[0])
         << " and "
         << ToString(roots[1])
         << endl;
    return 0;
}

