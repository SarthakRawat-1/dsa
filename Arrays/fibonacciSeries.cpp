// The Fibonacci series is a sequence of numbers where each number (after the first two) is the sum of the two preceding ones. The sequence starts with 0 and 1, and then the following numbers are generated based on the rule.

#include <iostream>
using namespace std;

int main() {
    int n; // Declare an integer variable 'n' to store the term number.

    cout << "Enter the term :- ";
    cin >> n;

    int arr[100]; // Declare an array 'arr' of size 100 to store Fibonacci numbers.

    arr[0] = 0; // The first term of the Fibonacci series is always 0.
    arr[1] = 1; // The second term of the Fibonacci series is always 1.

    // A loop to calculate the Fibonacci numbers from the 3rd term to the nth term.
    for (int i = 2; i <= n - 1; i++) { // Loop starts at index 2 (third term) and runs until the (n-1)th term.
        arr[i] = arr[i - 1] + arr[i - 2]; // Each term is the sum of the previous two terms.
    }

    cout << "The term " << n << " of the fibonacci series is :- "  << arr[n - 1];
}