
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;

static volatile double garbage_can;
// C++ compiler will delete codes whose results are not used.
// This is a good thing for speeding up real programs.
// But for benchmarking, we want to perform the computation without using the results.
// So we use a "garbage can" to store the results in a way that
// the compiler cannot optimize the codes away.

template <class F>
double time_f_at_n (F&& f, long long n) {
    auto t0 = std::chrono::steady_clock::now();
    garbage_can /= 2;
    garbage_can += static_cast<double>(f(n)); // throw the result away
    auto t1 = std::chrono::steady_clock::now();
    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count();
    return double(ns) / 1e9; // convert to seconds
}


// The recursion method
double fib_rec(long long n) {
    if (n <= 1) return double(n);
    return fib_rec(n-1) + fib_rec(n-2);
}

// Dynamic programming
double fib_dp(long long n) {
    if (n <= 1) return n;
    double  a = 0;
    double  b = 1;
    double  c = 0;
    for (long long i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Matrix and square and multiply
struct M22 {
    double a, b, c, d;
};
M22 mul(const M22& X, const M22& Y) {
    return {
        X.a*Y.a + X.b*Y.c,  X.a*Y.b + X.b*Y.d,
        X.c*Y.a + X.d*Y.c,  X.c*Y.b + X.d*Y.d
    };
}
double fib_matrix(long long n) {
    if (n == 0) return 0;
    M22 Q{1,1,1,0};
    M22 res{1,0,0,1}; // identity
    while (n) {
        if (n & 1) res = mul(res, Q);
        Q = mul(Q, Q);
        n >>= 1;
    }
    return res.b;
}
double fib_sleep(long long n) {
    usleep(n);
    return 1;
}

int main() {
    cout << "fib_rec spends " << time_f_at_n(fib_rec, 42) << " seconds" << endl;
    cout << "fib_dp spends " << time_f_at_n(fib_dp, 44442222) << " seconds" << endl;
    cout << "fib_matrix spends " << time_f_at_n(fib_matrix, 4444444422222222) << " seconds" << endl;
    cout << "fib_sleep spends " << time_f_at_n(fib_sleep, 5555555) << " seconds" << endl;
    cout << garbage_can << endl; // to avoid "unused variable" warning
}
