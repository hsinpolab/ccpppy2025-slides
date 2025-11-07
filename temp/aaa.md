# 1106 Human Genome Project

Due to the sheer amount and difficulty of this assignment,
we haven't finished the testing data.
You can, however, start working on the problems.
When the testing data is ready,
we will give you a new invitation link
and at least another week to finish the assignment.

## Time it  [10 points]

Finish the following program

```C++
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
M22 operator*(const M22& X, const M22& Y) {
    return {
        X.a*Y.a + X.b*Y.c,  X.a*Y.b + X.b*Y.d,
        X.c*Y.a + X.d*Y.c,  X.c*Y.b + X.d*Y.d
    };
};
double fib_matrix(long long n) {
    if (n == 0) return 0;
    M22 Q{1,1,1,0};
    M22 res{1,0,0,1}; // identity
    while (n) {
        if (n & 1) res = res * Q;
        Q = Q * Q;
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
    cout << garbage_can << endl;
    cout << "fib_dp spends " << time_f_at_n(fib_dp, 44442222) << " seconds" << endl;
    cout << garbage_can << endl;
    cout << "fib_matrix spends " << time_f_at_n(fib_matrix, 4444444422222222) << " seconds" << endl;
    cout << garbage_can << endl;
    cout << "fib_sleep spends " << time_f_at_n(fib_sleep, 5555555) << " seconds" << endl;
    cout << garbage_can << endl;
}
```

One thing to keep in mind is that some functions are too fast that
CPU may spend more time on the benchmarking code than the function itself.
For this kind of function,
we can run it multiple times and compute the average.
The problem is that we don't know how many times we should run it
unless we time it first.
You see the dilemma?

To solve this, time the function once first.
If it spends less than `1` seconds,
run it 10 times and take the average.
If it is still less than `1` second,
run it 100 times and take the average.
And so on.
The `<chrono>` library is useful for timing.

## Human genome project  [9 points]

[Wiki](https://en.wikipedia.org/wiki/Human_genome_project)

The following toy model demonstrate the difficulty of reading human DNA.
Imagine that there is a circular DNA sequence of length $1000$,
such as $x_1, x_2, \dotsc, x_{1000} =$ `ACGTACGTACGT...`.
We said that it is circular because the end connects to the beginning,
$x_{1001} = x_1$.
With the PCR technology, we can replicate the DNA sequence multiple times
so we always have enough copies to read.

Now, reading $1000$ letters in one go is too time consuming
because each letter takes one full second (that's a lot in the AI era).
So we developed a chip with $1000$ nanopores;
each nanopore can read $100$ letters in in parallel,
so the whole task takes $100$ seconds.
So instead of $(x_1, x_2, \dotsc, x_{1000})$,
the chip will return

- $(x_1, x_2, \dotsc, x_{100})$,
- $(x_2, x_3, \dotsc, x_{101})$,
- $(x_3, x_4, \dotsc, x_{102})$,
- and so on, until
- $(x_{1000}, x_1, \dotsc, x_{999})$,

except that the order of the sequences is shuffled
(because DNA floats in a liquid container).
Your program `dna.cpp` should read `dna.txt`
and try to recover the original sequence.

There are two catches

- The DNA reader is not perfect,
  it makes mistakes once per $100$ letters.
- There are multiple possible solutions due to cyclic shifts.
  Output the lexicographically smallest one.

We believe that `<map>`is the best data structure for this problem.

## RSA interactive program [8 points]

[Wiki](https://en.wikipedia.org/wiki/RSA_cryptosystem)

Upload a file called `keygen.cpp`.
Your program should take an input $n$. and pick two distinct prime numbers
$p$ and q$ between $2^n$ and $2^{n+1}$.
Let $N = p \cdot q$ and $e = 65537$ be the public key
and compute the corresponding private key $d$.
Then create a `private_key.txt` to store $p$, $q$, and $d$
(one number per line),
and a `public_key.txt` to store $N$ and $e$ (one number per line).

TA's program `encrypt.py` reads the public key
and stores the cipher text to `cipher.txt`.

Upload another file `decrypt.cpp` that reads the cipher text
and private key to output **plain** (decrypted message).

All numbers are in hexadecimal format, like `0x1234abcd`.

## Baby step giant step [7 points]

`E` is a class that overloads `+`, `-`, and `zero()`.
Its instances can also be put in `set`.
Your program `order.cpp` should contain a function template

```C++
template <typename E>
long long order(const E& P) {
    // your code here
}
```

such that `order(P)` returns the smallest positive integer $k$
such that `P + P + ... + P == P.zero()`.

Examples:

- `x + y` means $xy \bmod 1234567$.
- Elliptic curves $y^2 = x^3 + 1$ over GF(99999989).

## Array editing monoid [6 points]

For large databases, some actions need to be bundled together.
For instance, if Alice wants to pay Bob $10$ dollars,
then we need

- reduce Alice's balance by $10$ dollars, and
- increase Bob's balance by $10$ dollars.

If, for instance, Alice's balance is reduced
but somehow something is wrong with Bob's balance,
then we need to roll back Alice's balance.
Otherwise, the sum of all balances will not be correct.

In database theory, this is called a transaction.
Either all actions in a transaction are executed,
or none of them are executed.

Your `edit.cpp` should implement array editing monoid.
An array editing action is something like the following

```txt
Alice += 10
Bob += -10
Charlie = 100
```

Your program should read a list of array editing actions from `actions.txt`
and output the simplified list of actions to `simplified.txt`.
For instance,

- `Alice += 10` followed by `Alice += -5`
  can be simplified to `Alice += 5`.
- `Bob += -10` followed by `Bob = 100`
  can be simplified to `Bob = 100`.
- `Charlie = 100` followed by `Charlie += 50`
  can be simplified to `Charlie = 150`.

## Compile command

We use

```shell
    g++-14 -std=c++26 ijklmn.cpp -o opqrst
```

to compile your C++ programs.
Here, `g++-14` means that we are using the version 14 of GNU C++ compiler.
The option `-std=c++26` means that we are using C++26 standard.
The input file is `ijklmn.cpp`,
and `opqrst` is the output file because it is after `-o`.

I understand that it's compilcated if you are new.
Most of the time,

```shell
    g++ ijklmn.cpp -o opqrst
```

is equivalent to the line above.
