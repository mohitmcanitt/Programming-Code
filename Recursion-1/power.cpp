#include <iostream>
using namespace std;

// Naive Iterative Method
// Time Complexity: O(b)
int powerIterativeNaive(int a, int b) {
    int res = 1;
    while (b > 0) {
        res *= a;
        b--;
    }
    return res;
}

// Optimized Iterative using Exponentiation by Squaring
// Time Complexity: O(log b)
int powerIterativeFast(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

// Naive Recursive Method
// Time Complexity: O(b)
int powerRecursiveNaive(int a, int b) {
    if (b == 0)
        return 1;
    return a * powerRecursiveNaive(a, b - 1);
}

// Optimized Recursive using Exponentiation by Squaring
// Time Complexity: O(log b)
int powerRecursiveFast(int a, int b) {
    if (b == 0)
        return 1;
    int half = powerRecursiveFast(a, b / 2);
    if (b & 1)
        return a * half * half;
    return half * half;
}

int main() {
    cout << powerIterativeNaive(5, 6) << endl;   // Output: 15625
    cout << powerIterativeFast(5, 6) << endl;    // Output: 15625
    cout << powerRecursiveNaive(5, 6) << endl;   // Output: 15625
    cout << powerRecursiveFast(5, 6) << endl;    // Output: 15625
}
