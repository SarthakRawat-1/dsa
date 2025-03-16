// The Ackermann function is a classic example of a recursive function that is not primitive recursive, meaning it grows very quickly and goes beyond simple loops or primitive recursive algorithms like factorial, Fibonacci, etc. The Ackermann function is used to illustrate deep recursion.
// For non-negative integers m and n, the Ackermann function A(m, n) is defined as :-
//           { n + 1                   if m = 0
// A(m, n) = { A(m − 1, 1)             if m > 0 and n = 0
//           { A(m - 1, A(m, n − 1))   if m > 0 and n > 0
// The function grows rapidly with increasing values of m and n. Even for relatively small values of mm and nn, the function can result in very deep recursion.

// The function involves two levels of recursion :- The first level reduces the value of m step-by-step. The second level works on reducing n recursively.
// The key is to have a proper base case that stops the recursion (i.e., when m = 0).

#include <iostream>
using namespace std;

// Ackermann function definition
int ackermann(int m, int n) {
    // Base case when m = 0
    if (m == 0) {
        return n + 1;
    }
    // Recursive case when m > 0 and n = 0
    else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    }
    // Recursive case when both m > 0 and n > 0
    else if (m > 0 && n > 0) {
        return ackermann(m - 1, ackermann(m, n - 1));
    }

    // This case will never be reached if inputs are valid (non-negative integers)
    return -1;
}

int main() {
    int m, n;

    cout << "Enter value for m: ";
    cin >> m;
    cout << "Enter value for n: ";
    cin >> n;

    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;
    
    return 0;
}

// The Ackermann function is primarily used in theoretical computer science to demonstrate the concept of recursive functions and to show the limits of primitive recursion. It also serves as a test case for recursion depth in programming languages.
// For large values of mm, you may run into stack overflow errors due to the deep recursion, especially in languages like C++ where the default recursion stack depth is limited. Optimizations such as memoization are not effective here due to the nature of the function, but an iterative approach can be used in some cases to mitigate deep recursion problems.
