#include <iostream>
#include <string>
using namespace std;

// Function to find the 1's complement of a binary string
string onesComplement(string binary) {
    string result = ""; // To store the 1's complement result

    // Iterate through each bit of the binary string
    for (char bit : binary) {
        // If the bit is '0', change it to '1', and vice versa
        result += (bit == '0') ? '1' : '0';
    }

    return result; // Return the 1's complement
}

// Function to find the 2's complement of a binary string
string twosComplement(string binary) {
    // Step 1: Find the 1's complement of the binary string
    string oneComplement = onesComplement(binary);

    // Step 2: Add 1 to the 1's complement (binary addition)
    int n = oneComplement.length();
    string result = oneComplement; // Start with the 1's complement
    bool carry = true; // Initially, we need to add 1 (so carry is true)

    // Traverse from the least significant bit to the most significant bit
    for (int i = n - 1; i >= 0; i--) {
        if (carry) {
            // If there's a carry, add 1 to the current bit
            if (result[i] == '1') {
                result[i] = '0'; // 1 + 1 = 10, so we put '0' and carry over the '1'
            } else {
                result[i] = '1'; // 0 + 1 = 1, no carry to propagate further
                carry = false; // Clear the carry, as it's been handled
            }
        } else {
            // No carry to add, so break out of the loop
            break;
        }
    }

    // If carry is still true after the loop, it means we need to add a new '1' at the start
    if (carry) {
        result = '1' + result; // Prepend '1' to the result
    }

    return result; // Return the 2's complement
}

int main() {
    string binary;
    cout << "Enter a binary number: ";
    cin >> binary; 

    cout << "1's Complement: " << onesComplement(binary) << endl;
    cout << "2's Complement: " << twosComplement(binary) << endl;

    return 0;
}
