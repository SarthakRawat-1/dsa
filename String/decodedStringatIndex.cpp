// Problem Statement :- https://leetcode.com/problems/decoded-string-at-index/description/

// Say, you have :- abc and you are asked to find the fifth character. You can do it in two ways :- Append this string one more time you get :- abcabc, b is the fifth chaacter. Or you can just roll over after the end of string, so a is the 4th character also, b is the 5th character, and c is the 6th character.
// Hence, we can do modulo of character to find with the size of string. In our case :- 5 % 3 = 2
// This is how we are going to approach this problem sintead of making the whole resultant string according to algorithm and then fidning character in it.
// What if you get result of modulo as 0? If we had sixth character then 6 % 3 = 0 This means that it is the last character of string i.e. c in our case.

// Consider this eg :- xy22 We know initially string size = 2, but then we encountered 2, so size becomes size * 2 = 4, then again comes 2, so size now becomes size * 2 = 8 so now if we are asked k = 5. Here, we know that if k % size == 0, then ans is last character. Start a pointer i from last character. 
// For our case we are getting 5 % 8 = 5. This can't be our answer. So move i left by one but before that check the value at i, it is 2, hence, size now becomes size / 2 = 4. Now 5 % 4 = 1, but result is not zero, so we have not got our answer yet.
// Again move to left by one, size becomes size / 2 = 2. Now i points to y. Hence, only xy is left. Doing 5 % 2 = 1, again result is not zero. So, we will go one left. Now size will only decrease by 1 as we are decreasing only one character.
// Now, 5 % 1 = 0, result is 0. Now where i is present, that will be our answer, in our case it is x.
// Consider :- a23, in this case size = 6, and if k = 6, then k % size = 0, i is pointing to 3, so 3 should be answer. But our answer is a. Hence, if result of modulus is 0, then also check if the element pointed to by k is a character or a digit.

#include <bits/stdc++.h>
using namespace std;

string decodeAtIndex(string s, int k) {
    // Step 1: Find the length of the expanded string
    // The variable 'size' will store the total length of the expanded string based on the current characters and digits.
    long long size = 0;  // Using long long to handle large sizes since the expanded string can be very large.

    // Loop through the string to calculate the total size of the expanded string without actually expanding it.
    for (char &ch : s) {
        // If the current character is a digit (e.g., '2', '3'), multiply the current size by this digit.
        if (isdigit(ch)) {
            size = size * (ch - '0');  // Multiply size by the integer value of the digit.
        } else {
            // If the current character is an alphabet, simply increase the size by 1 (representing one character).
            size++;
        }
    }

    // Step 2: Traverse the string in reverse to find the character at index k in the expanded string.
    // We'll simulate "unexpanding" the string to avoid building a huge string in memory.
    for (int i = s.length() - 1; i >= 0; i--) {
        // Update k to handle the case where the index rolls over (using modulus operator).
        k = k % size;

        // If k is 0 and the current character is an alphabet, return this character as the answer.
        if (k == 0 && isalpha(s[i])) {
            return string(1, s[i]);  // Convert the character to a string and return.
        }

        // If the current character is an alphabet, reduce the size by 1 since we're unexpanding it.
        if (isalpha(s[i])) {
            size--;
        } else {
            // If the current character is a digit, divide the size by the integer value of the digit.
            // This effectively "undoes" the expansion done by that digit.
            size = size / (s[i] - '0');
        }
    }

    return "";  // Return an empty string in case of unexpected input (should not occur with valid input).
}

int main() {
    string s = "leet2code3";
    int k = 10;
    cout << decodeAtIndex(s, k) << endl;
    return 0;
}