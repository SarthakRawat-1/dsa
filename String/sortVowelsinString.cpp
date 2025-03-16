// Problem Statement :- https://leetcode.com/problems/sort-vowels-in-a-string/description/

// Since, our string can contain both uppercase and lowercase letters meaning even vowels. We have to make sure to check that case as well, as each uppercase vowel is smaller than lowercase 'a', so they will come before that.
// First, select vowels. Then sort the vowels. Then insert the vowel at right position. 
// Selecting and sorting vowels can be done in one step. We can declare two vectors both of size 26, just for easy mapping (we only reuqire 5 positions out of these though for our vowels), one for storing uppercase vowels count and other for lowercase vowels count.
// Then traverse the string, and when you encounter a vowel, store it's count in the appropriate vector. Obviously for sorting the vowels only, you can just run a for loop from 0 to 26, and we can make another string to store this result. Now, initially we can append all the uppercase vowels to the string and later we can append lowercase vowels. First we append 'A' till it's count, then 'E' , ....., then we start appending 'a' till it's count, then 'e' and so on.
// Now using this result string, we have to update vowels in original string at their position. One way to do this is to again traverse an array and check if the character is a vowel or not, if it is, then replace it with character in result string one by one. But we have a more efficient way to handle this.
// When we first traversed the string for storing vowels count, we were first checking if the element is a vowel or not. Here if it is a vowel we can now do an additional task. We replace the vowel with a # symbol. This works becauseonce we are storing the count of the vowel, we don't really need to know the exact vowel at that's place as it will be occupied by vowel from result string.
// In this way, we can avoid writing big if else condition to check if letter is vowel or not when we will update vowels in original string from result string. We only have to check for # now.
// To replace # with correct vowel from result bring we can use pointers. One pointer starting from result string, another from original string with # replaced. 

#include <bits/stdc++.h>
using namespace std;

string sortVowels(string s) {
    // Step 1: Create two vectors to store the counts of lowercase and uppercase vowels.
    // 'lower' is used for lowercase vowels, 'upper' is used for uppercase vowels.
    vector<int> lower(26, 0); // Size 26 for each alphabet letter, though we only need 5 for vowels
    vector<int> upper(26, 0); // Same size for uppercase vowels

    // Step 2: Traverse the string 's' to find vowels.
    for (int i = 0; i < s.size(); i++) {
        // If the character is a lowercase vowel, increase the count and replace it with '#'
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            lower[s[i] - 'a']++;  // Increment the count for the corresponding vowel
            s[i] = '#';  // Replace the vowel with '#'
        }
        // If the character is an uppercase vowel, increase the count and replace it with '#'
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            upper[s[i] - 'A']++;  // Increment the count for the corresponding uppercase vowel
            s[i] = '#';  // Replace the vowel with '#'
        }
    }

    // Step 3: Create a string to store the sorted vowels based on ASCII order
    string vowelResult = "";

    // Step 4: Add sorted uppercase vowels to 'vowelResult'
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;  // Map index back to uppercase letter (A-Z)
        while (upper[i]) {  // While there are occurrences of this vowel
            vowelResult += c;  // Append the vowel to 'vowelResult'
            upper[i]--;  // Decrease the count of that vowel
        }
    }

    // Step 5: Add sorted lowercase vowels to 'vowelResult'
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;  // Map index back to lowercase letter (a-z)
        while (lower[i]) {  // While there are occurrences of this vowel
            vowelResult += c;  // Append the vowel to 'vowelResult'
            lower[i]--;  // Decrease the count of that vowel
        }
    }

    // Step 6: Replace the '#' placeholders in the original string with sorted vowels
    int first = 0;  // Pointer for the original string 's'
    int second = 0;  // Pointer for the 'vowelResult' string

    // Traverse the string 's' and replace '#' with the sorted vowels from 'vowelResult'
    while (second < vowelResult.size()) {
        if (s[first] == '#') {
            s[first] = vowelResult[second];  // Replace the '#' with the sorted vowel
            second++;  // Move to the next vowel in 'vowelResult'
        }
        first++;  // Move to the next character in 's'
    }

    // Step 7: Return the modified string 's' with sorted vowels and consonants in place
    return s;
}


int main() {
    string str = "Romae";

    cout << "The word with vowels sorted is :- " << sortVowels(str) << endl;

    return 0;
}