// Removing last set bit implies converting rightmost set bit to 0.

// The operation to clear the rightmost set bit can be done using the expression :- n & (n - 1)
// This works because subtracting 1 from n flips (i.e. converts 0 to 1 and vice versa) all the bits after the rightmost set bit (including the rightmost set bit itself). When we apply a bitwise AND between n and n - 1, it clears the rightmost set bit while leaving all other bits unchanged.

#include <iostream>
using namespace std;

// Function to remove the rightmost set bit
int removeRightmostSetBit(int n) {
    // The expression (n & (n - 1)) removes the rightmost set bit of n
    return n & (n - 1);
}

int main() {
    int n = 12;
    cout << "Original number: " << n << endl;
    int result = removeRightmostSetBit(n);
    cout << "Number after removing rightmost set bit: " << result << endl;

    n = 15;
    cout << "Original number: " << n << endl;
    result = removeRightmostSetBit(n);
    cout << "Number after removing rightmost set bit: " << result << endl;

    return 0;
}
