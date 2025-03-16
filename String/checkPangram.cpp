// Problem Statement :- https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

// We can make an array with size 26 represnting every English alphabet, which stores false as every element intially. Now, using a for each loop, we can traverse through the given sentence, and mark true for the corrseponding character index present in the array.
// FInally after traversing the sentence, if there is any false element still present inside the array, we know the sentence is not a Pangram.

#include <bits/stdc++.h>
using namespace std;

// Function to check if a given sentence is a pangram
bool isPangram(string sentence) {
    // Create an array of size 26 initialized to false, representing the 26 letters of the alphabet
    bool present[26] = {false};

    // Traverse through the sentence. You can also use a normal for loop. 
    for (char c : sentence) {
        // Mark the corresponding index in the array as true
        present[c - 'a'] = true; // 'a' - 'a' = 0 which is first index in our array, which represensts character 'a'. Similarly, it'll give index for other chaarcters.
    }

    // Check if all 26 letters are present
    for (int i = 0; i < 26; i++) {
        if (!present[i]) {
            // If any letter is missing, return false
            return false;
        }
    }

    // If all letters are present, return true
    return true;
}

int main() {
    string sentence1 = "thequickbrownfoxjumpsoverthelazydog";
    if (isPangram(sentence1)) {
        cout << "True" << endl;  
    } else {
        cout << "False" << endl;
    }

    string sentence2 = "leetcode";
    if (isPangram(sentence2)) {
        cout << "True" << endl;  
    } else {
        cout << "False" << endl;
    }
}
