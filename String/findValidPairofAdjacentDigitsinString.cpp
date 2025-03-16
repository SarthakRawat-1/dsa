// Problem Statement :- https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/description/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to find a valid pair of digits in the string
string findValidPair(string s) {
    // Create a map to store the count of each digit in the string
    unordered_map<char, int> countDigits;

    // Count the occurrences of each digit in the string
    for (int i = 0; i < s.length(); i++) {
        countDigits[s[i]]++;
    }

    // Iterate through the string to find a valid pair
    for (int i = 0; i < s.length() - 1; i++) {
        char first = s[i];    // Current character
        char second = s[i + 1]; // Next character

        // Check if the two characters are different and if their counts match their numeric values
        if (first != second && 
            countDigits[first] == (first - '0') && 
            countDigits[second] == (second - '0')) {
            
            // If the conditions are met, create a result string with the pair
            string result;
            result += first;
            result += second;
            return result; // Return the valid pair
        }
    }

    // If no valid pair is found, return an empty string
    return "";
}

int main() {
    // Example input string
    string input = "224433";

    // Call the function to find a valid pair
    string result = findValidPair(input);

    // Output the result
    if (!result.empty()) {
        cout << "Valid pair found: " << result << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}