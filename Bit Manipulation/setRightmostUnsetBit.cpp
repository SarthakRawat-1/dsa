#include <iostream>
using namespace std;

// Function to set the rightmost unset bit in a given number n
int setRightmostUnsetBit(int n) {
    // n + 1 will flip all bits from the rightmost unset bit (0) to the end.
    // The rightmost unset bit (0) will become 1 when we do n | (n + 1).
    // This operation effectively sets the rightmost unset bit in n.
    return n | (n + 1);
}

int main() {
    int n1 = 6;  // Example 1: Input is 6, binary representation is 110
    int n2 = 15; // Example 2: Input is 15, binary representation is 1111

    // Output the result for n1
    // For n1 (6):
    //  - The binary representation is 110. The rightmost unset bit is at position 0 (the last bit).
    //  - After setting the rightmost unset bit, it becomes 111 (which is 7).
    cout << "After setting the rightmost unset bit in " << n1 << ": " << setRightmostUnsetBit(n1) << endl;
    
    // Output the result for n2
    // For n2 (15):
    //  - The binary representation is 1111. There are no unset bits (0) in this number.
    //  - When we add 1 to 15, it becomes 16 (binary: 10000).
    //  - The bitwise OR of 1111 (15) and 10000 (16) will give us 11111 (which is 31).
    cout << "After setting the rightmost unset bit in " << n2 << ": " << setRightmostUnsetBit(n2) << endl;

    return 0; // Indicate that the program ended successfully
}
