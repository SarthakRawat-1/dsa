// Problem Statement :- https://leetcode.com/problems/break-a-palindrome/description/

#include <bits/stdc++.h>
#include <string>
using namespace std;

// Function to break a palindrome and make it lexicographically smallest
string breakPalindrome(string pal) {
    int n = pal.length(); // Get the length of the palindrome
    
    // If the string has only one character, return an empty string
    if (n == 1) return "";
    
    // Iterate through the first half of the string
    for (int i = 0; i < n / 2; i++) {
        // Replace the first non-'a' character with 'a' and return immediately
        if (pal[i] != 'a') {
            pal[i] = 'a';
            return pal;
        }
    }
    
    // If all characters are 'a', replace the last character with 'b'
    pal[n - 1] = 'b';
    return pal; // Return the modified string
}


int main() {
    // Test cases
    string pal = "abccba";
    string result = breakPalindrome(pal);
    cout << result << endl; // Output: "aaccba"
    
    pal = "a";
    result = breakPalindrome(pal);
    cout << result << endl; // Output: ""
    
    return 0;
}
