#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function to convert a binary string to an integer
int binaryToInt(string binary) {
    int result = 0;    // This will store the integer value of the binary
    int power = 0;     // The current power of 2 (starting from rightmost bit)

    // Loop through each character in the binary string from right to left
    for (int i = binary.length() - 1; i >= 0; i--) {
        // If the current character is '1', add the corresponding power of 2
        if (binary[i] == '1') {
            result += pow(2, power); // Add 2^power to the result
        }
        power++; // Move to the next power of 2
    }

    return result; // Return the integer value of the binary string
}

// Function to convert an integer to a binary string
string intToBinary(int num) {
    if (num == 0) return "0"; // Special case for 0

    string binary = ""; // This will store the binary representation

    // Loop until the number becomes 0
    while (num > 0) {
        // If the current number is odd, append '1' to the binary string, else append '0'
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2; // Divide the number by 2 for the next iteration
    }

    return binary; // Return the final binary string. There is no need to reverse this because we were prepending the characters in binary.
}

int main() {
    string binary = "1101"; 
    int integerValue = binaryToInt(binary);
    cout << "Binary " << binary << " is equivalent to integer " << integerValue << endl;

    int num = 13; 
    string binaryValue = intToBinary(num);
    cout << "Integer " << num << " is equivalent to binary " << binaryValue << endl;

    return 0;
}
