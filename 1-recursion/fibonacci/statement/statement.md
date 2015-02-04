# Fibonacci

## Description

The Fibonacci numbers are given by the following recurrance relation:

$$ \left\{\begin{array}{l} F_0 = 0, F_1 = 1 \\
    F_{n+2} = F_{n+1} + F_n \end{array}\right. $$

Now you are given an integer $n$, please output the number $F_n$ modulo $10^9+7$.

**Note** Usually we use modulo to prevent calculating on large numbers. This is a simple way to check if your algorithm is correct or not.

You can utilize the file `fibonacci.cpp` to solve this problem. However, there may be some bugs inside!

## Input

An intger $n$.

## Output

Please output the value $F_n\mod 10^9+7$.

## Technical Specifications

* For at least 40% test cases, we have $0\le n\le 20$.
* For at least 60% test cases, we have $0\le n\le 10^5$.
* For at least 80% test cases, we have $0\le n\le 10^{18}$.
* For all test cases, we have $0\le n\le 10^{1000}$.

## Sample Input 1
```
4
```

## Sample Output 1
```
3
```

## Sample Input 2
```
5
```

## Sample Output 2
```
5
```
