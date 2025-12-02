#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

int main() {
    // keep N reasonably small for interactive runs
    const int N = 100000;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) A[i] = i;

    // parallel for must be inside a function (e.g., main)
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        A[i] *= A[i];
        int tid = omp_get_thread_num();
        // synchronize printing to avoid interleaved output
        #pragma omp critical
        cout << "thread #" << tid << " gets " << i << " -> " << A[i] << '\n';
    }

    return 0;
}
