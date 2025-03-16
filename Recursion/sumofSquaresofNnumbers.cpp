#include <iostream>
using namespace std;

// Recursive function to calculate the sum of squares of the first N numbers
int sumOfSquares(int n) {
    // Base case: If n is 0, the sum is 0 (no numbers to square)
    if (n == 0) {
        return 0;
    }

    // Recursive case: Sum of squares of first n numbers = n^2 + sum of squares of (n-1) numbers
    return (n * n) + sumOfSquares(n - 1);
}

int main() {
    int N;

    // Input: Asking the user to input the number N
    cout << "Enter the value of N: ";
    cin >> N;

    // If N is negative, we can handle it here, but for now, only positive integers are expected
    if (N < 0) {
        cout << "Please enter a non-negative integer." << endl;
    } else {
        // Output: Calling the recursive function and printing the result
        cout << "Sum of squares of first " << N << " numbers is: " << sumOfSquares(N) << endl;
    }

    return 0;
}
