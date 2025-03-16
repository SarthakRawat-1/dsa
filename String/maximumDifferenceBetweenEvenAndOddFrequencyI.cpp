// Problem Statement :- https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s) {
    // Create a map to store the frequency of each character in the string
    map<char, int> frequencyMap;
    
    // Iterate through the string to populate the frequency map
    for (char c : s) {
        frequencyMap[c]++; // Increment the frequency of the character
    }
    
    // Vectors to store the frequencies that are even and odd, respectively
    vector<int> evenFrequencies;
    vector<int> oddFrequencies;
    
    // Iterate over the frequency map to classify frequencies as even or odd
    for (const auto& pair : frequencyMap) {
        if (pair.second % 2 == 0) {
            // If frequency is even, add it to the evenFrequencies vector
            evenFrequencies.push_back(pair.second);
        } else {
            // If frequency is odd, add it to the oddFrequencies vector
            oddFrequencies.push_back(pair.second);
        }
    }

    // Find the maximum value from the oddFrequencies vector
    int maxOdd = *max_element(oddFrequencies.begin(), oddFrequencies.end());
    
    // Find the minimum value from the evenFrequencies vector
    int minEven = *min_element(evenFrequencies.begin(), evenFrequencies.end());
    
    // Return the difference between the maximum odd frequency and the minimum even frequency
    return maxOdd - minEven;
}

int main() {
    string s = "aababbb";
    int result = maxDifference(s);
    cout << "Maximum difference between even and odd frequencies: " << result << endl;
    return 0;
}