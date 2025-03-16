#include <iostream>
using namespace std;

// Recursive function to calculate the sum of first N natural numbers
int sumOfN(int n) {
    // Base case: If n is 0, the sum is 0
    if (n == 0) {
        return 0;
    }

    // Recursive case: sum of first n numbers is n + sum of first (n-1) numbers
    return n + sumOfN(n - 1);
}

int main() {
    int num;
 
    cout << "Enter a number N to find the sum of first N natural numbers: ";
    cin >> num;

    if (num < 0) {
        cout << "Sum of natural numbers is not defined for negative numbers." << endl;
    } else {
        cout << "Sum of first " << num << " natural numbers is " << sumOfN(num) << endl;
    }

    return 0;
}
