// Problem Statement :- https://leetcode.com/problems/sort-characters-by-frequency/

// One appraoch is to use a map and store frequency of every character in the string. Then, you can use a vector, which stores the character and it's frequency, for eg :- {{e, 2}, {r, 1}, {t, 1}}. Now, you can sort this vector based on frequency.
// We can optimize this further and do this without using a map. Because it is given, that input is from a - z or A - Z. The ASCII of z is 122, so we can just make a vector of size 123.
// Now, we can iterate over the string, and store character's frequency in index which resembles their ASCII value.
// We can't directly sort the vector because then frequency of characters may come ahead, and we want all of them to remain at their index, as that's how we know waht characters they are.
// Hence, instead of directly storing character's frequency, we will also store character with that. With this, we can directly sort the array, as we now also know the character associated with the frequency.

#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> P; // Defining a type alias 'P' for a pair of character and its frequency

// Function to sort characters in the string based on their frequency
string frequencySort(string s) {
    // Step 1: Create a vector of pairs, where each index represents a character's ASCII value.
    // The pair stores the character and its frequency.
    // The vector has size 123 because we are considering ASCII values from 0 to 122 (ASCII value of 'z').
    vector<P> vec(123);

    // Step 2: Iterate over the input string 's'
    for (char &ch : s) {
        // Retrieve the current frequency of the character from the vector.
        // The frequency is stored in the second element of the pair at the index corresponding to the character's ASCII value.
        int freq = vec[ch].second;
        
        // Update the pair in the vector: increment the frequency by 1 for the current character.
        vec[ch] = {ch, freq + 1};
    }

    // Step 3: Define a lambda function to sort the vector of pairs by frequency in descending order.
    // This compares two pairs (p1, p2) and returns true if the frequency (second element) of p1 is greater than p2.
    auto lambda = [&] (P &p1, P &p2) {
        return p1.second > p2.second;
    };

    // Step 4: Sort the vector based on frequency using the lambda comparator.
    // This will place characters with higher frequency at the beginning of the vector.
    sort(vec.begin(), vec.end(), lambda);

    // Step 5: Initialize an empty result string to store the final sorted string.
    string result = "";

    // Step 6: Iterate through the vector (ASCII range from 0 to 122) and append characters to the result string based on their frequency.
    for (int i = 0; i <= 122; i++) {
        // Only process characters with a frequency greater than 0.
        if (vec[i].second > 0) {
            // Retrieve the character and its frequency from the vector.
            char ch = vec[i].first;
            int freq = vec[i].second;
            
            // Create a string 'temp' consisting of 'freq' repetitions of the character 'ch'.
            // Example: if ch = 'e' and freq = 3, then temp = "eee".
            string temp = string(freq, ch);

            // Append the temporary string 'temp' to the result string.
            result += temp;
        }
    }

    // Step 7: Return the final sorted string, where characters appear based on their frequency.
    return result;
}


int main() {
    string s = "Shogun The Great Lord";

    cout << frequencySort(s) << endl;
}
