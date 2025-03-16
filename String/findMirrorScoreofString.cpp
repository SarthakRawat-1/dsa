// Problem Statement :- https://leetcode.com/problems/find-mirror-score-of-a-string/description/

// We will create a map, which keeps track of all the indices a particular character has appeared on (and has not been marked yet).
// Then whenevr we encounter a character while iterating, we will find it's mirror in map and find all the indices where it's mirror appears. 
// As we are populating the map while going from left to right, so obviously the largest index for any character in map is going to be at the end, which will also be the closest.
// Then we can simmply remove it from map, and increase the score accordingly. And ofcourse, we won't add the character which we found by iterating (if it's mirror is available in map, if it isn't then add that to map) to the map.

#include <bits/stdc++.h>
using namespace std;


// Function to calculate the mirror score of a string
long long calculateScore(string s) {
    int n = s.size(); // Get the length of the string

    // Map to store indices of each character in the string
    unordered_map<char, vector<int>> charIndices;
    long long ans = 0; // Variable to store the final score

    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        // Find the mirror character using the formula: mirror = 'a' + 'z' - s[i]
        char mirror = 'a' + 'z' - s[i];

        // Check if the mirror character exists in the map and has indices stored
        if (!charIndices[mirror].empty()) {
            // Calculate score based on the index difference
            ans += i - charIndices[mirror].back();
            
            // Remove the last occurrence of the mirror character from the map
            charIndices[mirror].pop_back();
        } else {
            // If no mirror character is available, add the current character index to the map
            charIndices[s[i]].push_back(i);
        }
    }

    // Return the total score
    return ans;
}

int main() {
    // Example usage of the function
    string s = "abcxyz";
    cout << "Mirror Score: " << calculateScore(s) << endl;

    return 0;
}