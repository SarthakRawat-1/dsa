// Problem Statement :- https://leetcode.com/problems/count-and-say/description/

// If n = 1, then ans is 1. If n = 2, then check n = 1, it is 1, which can be written as 1 times 1, so n = 2 is 11. Similarly, n = 3 willcheck n = 2 which is 11, i.e. 2 times 1, hence, asn of n = 3 is 21, and similarly for n = 4, ans will be 1211.
// We can solve this using Recursion. 

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    // Base case: If n is 1, return "1"
    if (n == 1) {
        return "1";
    } 

    // Get the result for (n - 1)
    string say = countAndSay(n - 1);

    string result = "";

    // Iterate through the current string (say)
    for (int i = 0; i < say.length(); i++) {
        char ch = say[i];
        int count = 1;  // Initialize count as 1, because every character is seen at least once

        // Count the number of consecutive occurrences of the current character
        while (i < say.length() - 1 && say[i] == say[i + 1]) {
            count++;
            i++;
        }

        // Append the count and the character to the result string
        result += to_string(count) + ch;
    }

    return result;  // Return the result string for the current n
}

int main() {
    int n = 6;

    // Print the nth term of the count and say sequence
    cout << countAndSay(n) << endl;

    return 0;
}
