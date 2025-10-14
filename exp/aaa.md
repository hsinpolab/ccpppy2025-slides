# 1099 Midterm Mock Exam

This is a mock exam and has no due.
There is no autograder;
check your answer by yourself.

On test day, half of the test cases are visible to you.
The other half are 
check

## Gamma function [20 points]

Gamma function is a generalization of factorial
in the sense that $\Gamma(n) = (n-1)!$ for positive integers n.
But gamma function is defined for positive real numbers
and satisfies $\Gamma(x + 1) = x \cdot \Gamma(x)$.

So, how to define $\Gamma(0.3)$?
It turns out that
$\Gamma(0.3) = \Gamma(1.3) / 0.3
= \Gamma(2.3) / 1.3 / 0.3
= \Gamma(3.3) / 2.3 / 1.3 / 0.3$
and so on.
That is to say, if we know $\Gamma(100.3)$, we can compute $\Gamma(0.3)$.
But how is that easier than finding $\Gamma(0.3)$ directly?

The trick is that $\ln(\Gamma(x))$ is almost linear in $x$ for large $x$.
So $\ln(\Gamma(n + a)) \approx (1 - a) \ln(\Gamma(n)) + a \ln(\Gamma(n + 1))$
for an integer $n$ and a real number $a \in (0, 1)$.

Your program `gamma.cpp` should take one positive real number $x \in (0, 10)$
and output $\Gamma(x)$ by first computing $\Gamma(100 + x)$
using the linear approximation above.
The following table shows some samples.

| x   | Your output      | Correct gamma    |
| --- | ---------------- | ---------------- |
| 1.1 | 0.95177529264437 | 0.95135076986687 |
| 2.2 | 1.10266783432144 | 1.10180249087971 |
| 3.3 | 2.68617608304545 | 2.68343738195577 |
| 4.4 | 10.1478078128180 | 10.1361018511551 |
| 5.5 | 52.4051274851690 | 52.3427777845535 |
| 6.6 | 345.092249354732 | 344.701924035220 |
| 7.7 | 2772.54805077322 | 2769.83036232731 |
| 8.8 | 26359.4865600057 | 26339.9863545086 |
| 9.9 | 289987.252103518 | 289867.703840110 |

## Tokenizer [10 points]

Play the industrial tokenizer at
<https://platform.openai.com/tokenizer>.

Here we try to build a stupid tokenizer.
In `tokens.txt`, you are given a list of tokens in the following format:

```txt
1 e
2 i
3 a
4 n
5 s
...
19 er
20 in
21 ti
22 on
23 es
...
```

Your program `tokenizer.cpp` should take a line of string `s`
and output a list of integers using greedy matching of tokens.

- For example, if the input is `integer`,
  then both `2 i` and `20 in` can match the prefix,
  so the first integer should be `20`.
- Next we try to match `teger`.
  Since `24 te` is better than `8 t`, we should choose `24`.
- Now we are left with `ger`.
  Since there is no `ge` in the token list, we should choose `16 g`.
- Finally, `er` is `19`.

To conclude, the output should be `20 24 16 19`.

For if the sentence contains space, output `0`.
Anything other than lowercase letters and spaces are not allowed.

## Square and Multiply [5 points]

Read the [wikipedia](https://en.wikipedia.org/wiki/Elliptic_curve_point_multiplication)
for how to add two points on an elliptic curve.
You also need to know how to find $1/n$ modulo a prime $p$:
$1/n \equiv n^{p-2} \mod p$.

Consider the elliptic curve $y^2 = x^3 + 1$ modulo $p = 99999989$.
Consider a starting point $P = (32540029, 17791926)$ on the curve.
Your program `elliptic.cpp` should take one `long long` $n \in [1, 2^{63}]$
and output the point $n \cdot P$ on the curve.

Use the following SageMath code to verify your answer.

```python
E = EllipticCurve(GF(99999989), [0, 0, 0, 0, 1])
P = E(32540029, 17791926)
print(P * 123456789)
```
