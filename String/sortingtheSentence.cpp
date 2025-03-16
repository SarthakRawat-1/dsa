// Problem Statement :- https://leetcode.com/problems/sorting-the-sentence/description/

// First, we will have to extract individual words out of the sentence. For this we can make a temp string, and then iterate over the sentence till we get the first white space. End iteration here and store the first word in temp. In this word (and every other word) we know that the last character will be a number, which will indicate it's position.
// Before continuing iteration we will again make temp empty as we now know where the first word is going to be. Now iterate till the next white space to get the second word. Again it's last character will tell you the position. 
// Continue doing this for the rest of words present in sentence. 
// But how are we going to make the sorted sentence?
// We know that the numbers are going to be from 1 to 9. We can just make a vector with 10 as size such that the last index is 9. Then based on the number at the end of string, we can store the string in appropriate index. Obviously, this would mean that 0 index will be empty. Also other index which do not contain a word from the sentence will be empty.
// Now using this vector, we can combine the elements with whitespace between them to form the sorted sentence.

#include <bits/stdc++.h>
using namespace std;

string sortSentence(string s) {
    // Step 1: Create a vector of size 10 (indices 0-9) to store the words in the correct position. Intialize every element with empty string.
    vector<string> words(10, "");

    string temp = "";  // To temporarily hold each word
    int n = s.length();

    // Step 2: Iterate through the string to extract words
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            // If we encounter a space, the word is complete.
            // The last character of the word is a number representing its position.
            int position = temp.back() - '0';  // Convert the last character (digit) to an integer.
            temp.pop_back();  // Remove the last character (the number) from the word
            words[position] = temp;  // Place the word in the appropriate index of the vector
            temp = "";  // Reset temp for the next word
        } else {
            // Add the current character to temp to form the current word
            temp += s[i];
        }
    }

    // Step 3: Handle the last word after the loop
    int position = temp.back() - '0';  // Get the position of the last word
    temp.pop_back();  // Remove the number from the word
    words[position] = temp;  // Place the last word in the correct position
    // The reason for handling the last word outside the loop is because the loop is designed to split words based on spaces (' '). After the loop ends, the last word in the sentence is still in temp because there is no space after the final word to trigger its processing.
    // When the loop finishes, temp still holds the last word, and its corresponding number is still attached at the end. So, we need to process this last word after the loop to place it in the correct position in the words vector.
    
    // Step 4: Combine the words from the vector to form the sorted sentence
    string result = "";  // To store the final sentence

    for (int i = 1; i <= 9; i++) {
        if (words[i] != "") {
            if (result != "") {
                result += " ";  // Add a space before appending the next word (except for the first word)
            }
            result += words[i];  // Append the word to the result
        }
    }

    return result;  // Return the final sorted sentence
}

int main() {
    string s1 = "is2 sentence4 This1 a3";
    cout << "Sorted sentence: " << sortSentence(s1) << endl;

    string s2 = "Myself2 Me1 I4 and3";
    cout << "Sorted sentence: " << sortSentence(s2) << endl;

    return 0;
}
