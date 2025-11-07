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

## Baby step  giant step [7 points]

Upload a file called `ear_brain_mouth.cpp`
that takes one integer in the range $[10, 1000]$
and prints its square to the screen.

For instance, if the input is `30`, the output should be `900`.

## Array editing monoid [6 points]

Upload a file called `ear_ear_brain_mouth.cpp`
that takes two integers in the range $[10, 1000]$
and prints their sum to the screen.

For instance, if the input is `100 200`, the output should be `300`.

## Understanding GitHub interface

At the top of this page, you should see

```text
forked from hsinpolab/ccpppy2025-0910-ear-brain-mouth-aaa
```

This `hsinpolab` is a GitHub organization created for this course.
This `ccpppy2025-0910-ear-brain-mouth-aaa` is TA's copy of this assignment.
You can click the hyperlink to see if there is anything new.
Somethins TA may fix typos or add useful hints.
If you have no premission to see the repo, please contact TA.

You might also see

```text
This branch is 5 commits ahead of hsinpolab/ccpppy2025-0910-ear-brain-mouth-aaa:main.
```

where `5` can be any number.
The trailing `main` means that you are on the `main` branch.
This is the default branch, so don't worry about that for now.
The word **ahead** means that you did something TA didn't do.
For example,
you are trying to finish this assignment while TA doesn't need to.

However, if you see that your branch is **1 commit behind**,
it means that TA did something you didn't.
This is usually because TA is trying to fix typos or add useful hints.
In this case, you should press **Sync fork** and **Update branch**.
Do not, listen very carefully, do not discard your commits.
Doing that will delete files you have uploaded.

Below **Sync fork**, you might see a red cross ❌.
This ❌ means that your files do not pass automatic checks.
Click ❌ and click **Details** to see what goes wrong.
Keep trying until you see a green check ✅.

At the top of the list of files, you shall see a folder `.github/workflows`.
Enter that folder to study `classroom.yml`,
the file that explains autograding tests.
It might help you understand what goes wrong.

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
