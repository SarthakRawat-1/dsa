// Problem Statement :- https://leetcode.com/problems/add-binary/description/

// Doing it manually is the best way.
// Explanation :- https://leetcode.com/problems/add-binary/solutions/3183205/1ms-beats-100-full-explanation-append-reverse-c-java-python3/

#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    string ans;        // To store the resulting binary sum
    int carry = 0;     // Carry value (like in normal addition)
    int i = a.length() - 1;  // Pointer to the last digit of string 'a'
    int j = b.length() - 1;  // Pointer to the last digit of string 'b'

    // Loop until both strings are completely processed 
    // and no carry is left
    while (i >= 0 || j >= 0 || carry) {

        // If 'a' still has digits left, convert char -> int and add to carry
        if (i >= 0)
            carry += a[i--] - '0';  
            // 'a[i] - '0'' converts char ('0'/'1') to integer (0/1)
            // i-- moves pointer to the left for next iteration

        // If 'b' still has digits left, convert char -> int and add to carry
        if (j >= 0)
            carry += b[j--] - '0';

        // Current bit result is (carry % 2)
        // Example: (0+1)=1 -> write 1, (1+1)=2 -> write 0, carry 1
        ans += (carry % 2) + '0';  
        // (carry % 2) gives remainder (0 or 1)
        // + '0' converts integer back to character '0' or '1'

        // Update carry for next step
        carry /= 2;  
        // Example: 2/2=1 carry forward, 1/2=0 means no carry
    }

    // At this point, the answer string is reversed 
    // (we added from LSB → MSB).
    reverse(begin(ans), end(ans));

    return ans;  // Return final binary sum
}

int main() {

}