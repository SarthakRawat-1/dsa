// Problem Statement :- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

// Brute Force :- Use one pointer on haystack and one on needle. Compare both. Whenever they are not same, increment the pointer on haystack by one. If they are same, increase both pointer by one. If during comparison, they are not same. Then reset pointer on haystack back to where it was and increase it by 1.

#include <bits/stdc++.h>
using namespace std;

// Function to find the index of the first occurrence of "needle" in "haystack"
int strStr(string haystack, string needle) {
    // Store the size of the haystack and needle strings
    int n = haystack.size(), m = needle.size();

    // Iterate through the haystack, ensuring there's enough room left for the needle
    for (int i = 0; i <= n - m; i++) {
        // Initialize two pointers:
        // - 'first' points to the current position in haystack
        // - 'second' points to the start of needle
        int first = i, second = 0;
        
        // Compare characters of haystack and needle as long as they match
        while (second < m) {
            // If characters don't match, exit the loop
            if (haystack[first] != needle[second]) {
                break;
            } else {
                // If characters match, increment both pointers
                first++;
                second++;
            }
        }

        // If we successfully compared all characters of needle (i.e., second == m)
        // return the starting index of the match in haystack (i.e., first - second)
        if (second == m) {
            return first - second;
        }
    }

    // If no match is found, return -1
    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "ll";

    cout << "Index of first occurrence: " << strStr(haystack, needle) << endl;

    return 0;
}

// Optimal Approach :- Consider the eg :- haystack = onionionson and needle = onions, they both will match till onion but then comes i which is different from s. At this point, first pointer will be at i (in haystack) and second at s (in needle). 
// We want to somehow know if some portion of haystack (other than the one it is now ofc), can match with some portion of needle. So, if we remove those i and s from those strings, we can see that, onion (from haystack before i) last two characters i.e. on and onion (from needle before s) first two characters i.e. on are matching. Rest of the string of needle, we will have to match with i and beyond in haystack.
// Hence, we can observe that some suffix of haystack is matching with some prefix of needle. In our case, as both onion are same, we can see that some in same onion, common prefix and suffix is on. So we can now observe that we can solve our problem using longest prefix suffix i.e. lps of n. 
// To know how to find lps, refer longestPrefixSuffix.cpp Just remember that we will check this using needle i.e. lps of s, go one back we arrive at n, it's lps table stores 2 in our case, so go to second index in needle which is i. on before this index i in needle and on in haystack before i are already matched. So just check, if the element at that index in needle which is i, is equal to first pointer element which is also i. They are equal, so continue. 
// Hence, in this way, we avoided moving first pointer behind. We only moved the second pointer.

#include <bits/stdc++.h>
using namespace std;

// Function to compute the longest prefix which is also a suffix (LPS) array for the needle
// The LPS array is used to avoid unnecessary comparisons while searching
void lpsfind(vector<int> &lps, string s) {
    // 'pre' is the length of the previous longest prefix suffix, and 'suf' is the current index
    int pre = 0, suf = 1;

    // Loop to compute LPS for each index in the needle
    while (suf < s.size()) {
        if (s[pre] == s[suf]) {
            // If characters match, increment both pre and suf, and store the LPS value
            lps[suf] = pre + 1;  
            suf++;               
            pre++;               
        } else {
            if (pre == 0) {
                // If there's no match and pre is 0, set lps[suf] to 0 and move suf ahead
                lps[suf] = 0;
                suf++;
            } else {
                // Otherwise, move 'pre' back to the last computed LPS value
                pre = lps[pre - 1];
            }
        }
    }
}

// Function to find the first occurrence of the needle in the haystack using the KMP algorithm
int strStr(string haystack, string needle) {
    // Step 1: Compute the LPS array for the needle
    vector<int> lps(needle.size(), 0);
    lpsfind(lps, needle);

    // Step 2: Initialize two pointers:
    // 'first' is for haystack and 'second' is for needle
    int first = 0, second = 0;

    // Step 3: Iterate through the haystack and compare characters with the needle
    while (second < needle.size() && first < haystack.size()) {
        if (needle[second] == haystack[first]) {
            // If characters match, move both pointers ahead
            second++;
            first++;
        } else {
            if (second == 0) {
                // If second pointer is at the start, increment the first pointer
                first++;
            } else {
                // Move the second pointer based on the LPS table to avoid re-checking characters
                second = lps[second - 1];
            }
        }
    }

    // Step 4: If the entire needle has been matched, return the starting index of the match
    if (second == needle.size()) {
        return first - second;  // Return the start index of the match in the haystack
    } else {
        return -1;  // If no match is found, return -1
    }
}

int main() {
    string haystack = "hello";
    string needle = "ll";

    cout << "Index of first occurrence: " << strStr(haystack, needle) << endl;

    return 0;
}