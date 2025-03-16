// Since string is like a 1D array. We can use array sorting algorithm to sort it in lexicographical order.
// But we can also sort a string without using those algorithms.

// Given :- All letters in string are lowercase.

// The logic to solve this is counting how many times each letter is present in the string. And then using that count, we can just create a new string and return that.
// For counting we can just use an array, like we used in checkPangram.cpp but this time our array will store count of letters instead of true and false.

#include <bits/stdc++.h>
using namespace std;

// Function to sort the string lexicographically using counting method
string sortString(string &str) {
    // Step 1: Create an array to store the count of each letter
    // The size of the array is 26, since there are 26 letters in the alphabet
    int count[26] = {0}; 

    // Step 2: Traverse through the input string and count the occurrences of each character
    for (char c : str) {
        // 'c - 'a'' gives the index of the character in the array (0 for 'a', 1 for 'b', etc.)
        count[c - 'a']++;
    }

    // Step 3: Construct the sorted string
    string result = ""; 

    // Step 4: Traverse the count array to append characters in lexicographical order
    for (int i = 0; i < 26; i++) {
        // 'i + 'a'' gives the character corresponding to index 'i'
        char currentChar = i + 'a'; 
        
        // Append 'currentChar' to the result string 'count[i]' times
        while (count[i] > 0) {
            result += currentChar;
            count[i]--; // Decrease the count for that character
        }
    }

    // Step 5: Return the final sorted string
    return result;
}

int main() {
    string str = "sarthak";

    string sortedStr = sortString(str);

    cout << "Sorted string: " << sortedStr << endl;

    return 0;
}
