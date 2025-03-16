// Problem Statement :- https://leetcode.com/problems/find-the-difference/description/

#include <bits/stdc++.h>
using namespace std;

char findTheDifference(string s, string t) {
    // // Approach 1 :- Using map
    // unordered_map<char, int> mp; // Map to store character counts for string `s`
    
    // // Count occurrences of each character in `s`
    // for (char &ch : s) {
    //     mp[ch]++;
    // }
    
    // // For each character in `t`, decrement the count in the map
    // // If the count goes below zero, that means this character is the extra one
    // for (char &ch : t) {
    //     mp[ch]--;
    //     if (mp[ch] < 0) { // When count is less than 0, `ch` is the extra character
    //         return ch;
    //     }
    // }
    
    // // If no extra character found, return '0' as a failsafe (though in the problem constraints this is not needed)
    // return '0';

    // // Approach 2 :- Using sum of ASCII values of characters for both strings, then take difference of both
    // int sum = 0; // Initialize sum to 0

    // // Sum all ASCII values of characters in `t`
    // for (char &ch : t) {
    //     sum += ch;
    // }

    // // Subtract ASCII values of characters in `s` from the sum
    // for (char &ch : s) {
    //     sum -= ch;
    // }

    // // After subtraction, `sum` will hold the ASCII value of the extra character
    // return (char)(sum);

    // Approach 3 :- Using XOR
    int XOR = 0; // Initialize XOR to 0

    // XOR all characters in `s`
    for (char &ch : s) {
        XOR ^= ch;
    }

    // XOR all characters in `t`
    for (char &ch : t) {
        XOR ^= ch;
    }

    // After XOR-ing all characters of `s` and `t`, only the extra character remains
    return (char)XOR;
}

int main() {
    string s = "abcd";
    string t = "abcde";

    cout << findTheDifference(s, t) << endl;
}