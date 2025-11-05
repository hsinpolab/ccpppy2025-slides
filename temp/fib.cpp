
#include <iostream>
#include <chrono>

static volatile double garbage_can;
// C++ compiler will delete codes whose results are not used.
// This is a good thing for speeding up real programs.
// But for benchmarking, we want to perform the computation without using the results.
// So we use a "garbage can" to store the results in a way that
// the compiler cannot optimize the codes away.

template <class F>
float time_f_at_n (F&& f, int n) {
    auto t0 = std::chrono::steady_clock::now();
    garbage_can = sqrt(garbage_can);
    garbage_can = static_cast<double>(f(n)); // throw the result away
    auto t1 = std::chrono::steady_clock::now();
    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
    return float(ns) / 1e9; // convert to seconds
}


// The recursion method
long long fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n-1) + fib_rec(n-2);
}

// Dynamic programming
long long fib_dp(int n) {
    if (n <= 1) return n;
    long long a = 0;
    long long b = 1;
    long long c = 0;
    for (unsigned i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Matrix and square and multiply
struct M22 {
    float a, b, c, d;
};
M22 mul(const M22& X, const M22& Y) {
    return {
        X.a*Y.a + X.b*Y.c,  X.a*Y.b + X.b*Y.d,
        X.c*Y.a + X.d*Y.c,  X.c*Y.b + X.d*Y.d
    };
}
M22 mpow(M22 base, unsigned e) {
    M22 res{1,0,0,1}; // identity
    while (e) {
        if (e & 1) res = mul(res, base);
        base = mul(base, base);
        e >>= 1;
    }
    return res;
}
uint64_t fib_matrix(unsigned n) {
    if (n == 0) return 0;
    M22 Q{1,1,1,0};
    return mpow(Q, n-1).a;
}

int main() {

}
