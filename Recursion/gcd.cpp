// We will find out GCD using Euclidean Algortihm.
// The Euclidean Algorithm is based on the principle that the GCD of two numbers also divides their difference. This is because of the properties of divisibility. If a number dd divides both a and b, it must also divide a − b. Therefore, the GCD of a and b is the same as the GCD of b and a % b.
// The steps of the algorithm are as follows :-
// 1. For two numbers a and b, subtract the smaller from the larger. Replace the larger number with the result of this subtraction.
// 2. Keep subtracting the smaller number from the result until one of the numbers becomes zero.
// 3. When one of the numbers becomes zero, the other number is the GCD of the original two numbers.

#include <iostream>
using namespace std;

// Function to find GCD using subtraction method
int gcd(int a, int b) {
    // If one of the numbers is 0, the GCD is the other number
    if (a == 0) return b;
    if (b == 0) return a;

    // Continue subtracting the smaller number from the larger number
    while (a != b) {
        if (a > b)
            a = a - b; // Subtract b from a if a is larger
        else
            b = b - a; // Subtract a from b if b is larger
    }

    // When both numbers become equal, that is the GCD. This is because the next step will result in one of the numbers becoming zero, which automatically means that the other number is GCD which is unchanged.
    return a;
}

int main() {
    int num1, num2;
    cout << "Enter two non-negative integers: ";
    cin >> num1 >> num2;

    int result = gcdSubtraction(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}

// This subtraction process can be optimized by using the remainder operation, which is the essence of the Euclidean Algorithm :- Instead of repeatedly subtracting, we calculate the remainder when the larger number is divided by the smaller number and replace the larger number with this remainder.
// The reason why this works is because we can think of remainders as result of multiple subtractions. But obviously remainder can't be negative, which is something that we also don't want as we want one of the number to become zero not negative.
// In this, we need not check for the larger or smaller number because the remainder operation, a % b, automatically gives a result that is less than b. This is because the remainder is defined as the amount left over after dividing a by b.
// If a < b, the remainder a % b will simply be a (because b doesn’t go into a at all, so the remainder is a itself).
// If a > b, the remainder a % b is the "reduced" equivalent of a in the context of mod b, meaning it represents the same residue class as the original number modulo b.
#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean Algorithm
int gcd(int a, int b) {
    // Loop until one of the numbers becomes zero
    while (b != 0) {
        // Calculate remainder of a divided by b
        int remainder = a % b;

        // Update a to b, and b to remainder
        a = b;
        b = remainder;
    }

    // When b becomes zero, a is the GCD
    return a;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers to find their GCD :- ";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);

    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
    return 0;
}

// Recursive Approach

#include <iostream>
using namespace std;

// Function to find GCD using the recursive subtraction method
int gcdSubtraction(int a, int b) {
    // Base case: If one number becomes zero, the other number is the GCD
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // If a is greater than b, subtract b from a and recursively call gcdSubtraction
    if (a > b)
        return gcdSubtraction(a - b, b);

    // If b is greater than or equal to a, subtract a from b and recursively call gcdSubtraction
    return gcdSubtraction(a, b - a);

    // If you want to use Remainder appraoch
    // Recursive case: call the function with the smaller number and the remainder
    // return gcdRecursive(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two non-negative integers: ";
    cin >> num1 >> num2;

    int result = gcdSubtraction(num1, num2);
    cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
