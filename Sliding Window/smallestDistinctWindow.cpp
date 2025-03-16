// Problem Statement :- https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1

// Brute Force :- Let's say you have "AABBBCBBAC" As there are 3 dsitinct characters, so we ignore substrings with length less than 3. Find all substrings with length 3 and check if any of them have all unqiue characters. If not, go to 4 and check if any of them contain all 3 characters. If not, increase length of substring again and again.

// Optimal Approach :- Consider :- "AABBBCBBAC" Start from first character A, it can't be answer, so increase size of window, AA also can't be answer, increase window size, AAB also can't be asnwer, increase windwo size again, AABB and AABBB also can't be answer. But, AABBBC can be answer, at this point window size is 6.
// Now decrease window size from left, we got ABBBC, it still has all 3 characters, so minimum substring till now is of 5 length. Decrease window, we got BBBC, this doesn't have A, so it can't be answer. So now, increase window length, BBBCB and BBBCBB can't be answer but BBBCBBA can be answer, however window size is now 7 which is more than 5 so ans is still 5. Decrease window size BBCBBA, BCBBA, and CBBA are all valid, so ans is now 4. 
// But after decreasing window again BBA is not valid, so increase window again. We got BBAC, which is valid, can't decrease it further. Decreasing window BAC is also valid. ans becomes 3. String is exhausted and 3 is our final answer. 
// To implement this, we can make a vector which stores count of each character. Use two pointers first (indicates beginning of substring) and second (indicates end of substring).
// We will find the total number of distinct characters in the string in a diff variable.
// Whenever we encounter a character, we will increase it's count in the vector. If that character was not present already i..e it's count was 0, then we will increase it's count but also we will decrease the diff by 1.
// When diff becomes 0, it means that we have found all distinct characters in the substring. So we will store it's length as a possible result. Now in this case, decrease the window size from left by moving first pointer and don't forget to decrease that character count by 1 in the vector. During this, if count of that character becomes 0, increase diff by 1.
// Increase thw window size (using second pointer) to check for that distinct character.

#include <bits/stdc++.h>
using namespace std;

int findSubString(string s) {
    vector<int> count(256, 0); // Vector to store count of characters

    int first = 0, second = 0; 
    int len = s.size(); // Intitally we assume that the shortest substring is the whole string itself.
    int diff = 0;
    
    // Calculat the number of unique characters in string
    while (first < s.size()) { // Traverse the whole string using first pointer
        if (count[s[first]] == 0) { // If count of the character pointed to by first pointer is 0, it is unique
            diff++; 
        }

        count[s[first]]++; // Increase count of the character pointed to by first pointer
        first++; // Move first pointer to next character
    }

    // Reset the count vector and first pointer for our main logic
    for (int i = 0; i < 256; i++) {
        count[i] = 0;
    }

    first = 0; 

    // While second pointer is less than the length of the string i.e. string has not exhausted
    while (second < s.size()) {
        while (diff && second < s.size()) { // While diff is not 0 i.e. we don't have all unique characters in our substring and second pointer is less than the length of the string (this condition is to prevent segmentation fault which can occur when second increases beyound the indexes of array and diff didn't become 0)
            if (count[s[second]] == 0) { // If count of the character pointed to by second pointer is 0, it is unique
                diff--;
            }

            count[s[second]]++; // Increase count of the character pointed to by second pointer
            second++; // Move second pointer to next character
        }

        // When diff becomes 0, it means that we have found all distinct characters in the substring. So update len variable.
        len = min(len, second - first); // We didn't do second - first + 1 here because we are incresing the second pointer in previous while loop after processing each character. After that loop, the second pointer is actually positioned one character beyond the current substring.

        while (diff != 1) { // diff is 0, so decrease the window size, till it doesn't become 1
            len = min(len, second - first); // Update len value
            count[s[first]]--; // Decrease count of the character pointed to by first pointer as we are decreasing the size of window.

            if (count[s[first]] == 0) { // If count of the character pointed to by first pointer becomes 0, increase diff by 1 as we have to start increasing the window again.
                diff++;
            }
                
            first++; // Move first pointer to next character which actually decreases the length of window
        }
    }

    return len;
}

int main() {
    string s = "AABBBCBBAC";

    cout << "Length of the smallest substring: " << findSubString(s) << endl;

    return 0;
}