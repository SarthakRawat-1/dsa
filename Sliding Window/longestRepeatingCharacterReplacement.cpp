// Problem Statement :- https://leetcode.com/problems/longest-repeating-character-replacement/description/

// Brute Force :- Enumerate all possible substrings using nested loops. For each substring, count the frequency of each character and check if making at most k replacements can turn it into a uniform string (i.e., substring length minus max character frequency ≤ k). Track the longest valid substring.
// Optimized Approach :- Maintain a sliding window with start index l and end index r.
// Keep a fixed-size array counts[26] to track character frequencies in the current window (since the input is uppercase letters).
// Also keep a variable maxCount: the highest frequency of any character seen so far in the window.
// Expand the window by moving r. For each s[r], increment its count and update maxCount.
// If the window size minus maxCount exceeds k, shrink from the left by moving l and decrementing the count of s[l].
// At each step, record the maximum window size r−l+1

#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();
    int maxLen = 0;

    // Try all possible substrings
    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0); // frequency of each character
        int maxFreq = 0;         // max frequency of any char in current substring

        // Expand substring from i..j
        for (int j = i; j < n; j++) {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            // length of current substring = j - i + 1
            // replacements needed = substring length - maxFreq
            int replacementsNeeded = (j - i + 1) - maxFreq;

            if (replacementsNeeded <= k) {
                // Valid substring, update max length
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

// Optimal Approach
int characterReplacement(string s, int k) {
    vector<int> counts(26, 0); // frequency of chars in current window
    int left = 0;              // left pointer of window
    int right = 0;             // right pointer of window   
    int maxCount = 0;          // highest freq of a single char in window
    int result = 0;            // store the longest valid substring length

    while (right < s.size()) {
        // Add current character to the window
        counts[s[right] - 'A']++;

        // Update maxCount (most frequent character in the window so far)
        maxCount = max(maxCount, counts[s[right] - 'A']);

        // Current window size = right - left + 1
        // If replacements needed > k, shrink window from left
        while ((right - left + 1) - maxCount > k) {
            counts[s[left] - 'A']--;
            left++;
        }

        // Update result with current valid window size
        result = max(result, right - left + 1);

        right++;
    }

    return result;
}

// If this Lazy optimized solution is confusing, calc Maxfreq
int characterReplacement(string s, int k) {
    vector<int> counts(26, 0);  // frequency of chars in current window
    int left = 0;               // left pointer of the window
    int maxCount = 0;           // max frequency of any char in the current window
    int result = 0;             // store the longest valid substring length
    int n = s.size();

    for (int right = 0; right < n; right++) {
        // include the new character into the window
        counts[s[right] - 'A']++;

        // recalculate maxCount (true max frequency in current window)
        maxCount = 0;
        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, counts[i]);
        }

        // If window is invalid, shrink from the left
        while ((right - left + 1) - maxCount > k) {
            counts[s[left] - 'A']--;
            left++;

            // recalculate maxCount after shrinking
            maxCount = 0;
            for (int i = 0; i < 26; i++) {
                maxCount = max(maxCount, counts[i]);
            }
        }

        // Update result with current valid window size
        result = max(result, right - left + 1);
    }

    return result;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl; 
    // Expected output: 4 (we can replace one 'B' -> "AAAA")
    return 0;
}
