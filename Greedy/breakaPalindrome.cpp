// Problem Statement :- https://leetcode.com/problems/break-a-palindrome/description/

// We will simply replace the first non-'a' character with 'a' and return the modified string. If all characters are 'a', we will replace the last character with 'b' and return the modified string.
// What if we have :- aabaa, in this case, if we change the first non-'a' character to 'a', it will become aaaaa, which is a palindrome. This happens because for odd length strings, if we change the middle charcacter, it will remain a palindrome. Hence, in this case also, we will change last character to 'b'.
// We will only check the first half of the string. This is because the second half is a mirror image of the first half. This will also help in simplifying the code for previous case, i.e. odd length and middle character to be changed. 

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
