// Problem Statement :- https://leetcode.com/problems/minimum-window-substring/

// Store char and their freq of string t in a map. Maintain a var for total no of char required also (starts from len of t), say countrequired.
// Start i and j from start of string s. Check if char at j is present in map and it's freq is greater than 0. If yes, take it and decrease freq by 1 (yes this can go negative as well) in map and also dec countrequired. Increase j.
// If the char at j is not present in map, then put it in map and make it freq decrease by -1 (starting from -1 and going further down) to track that we don't want this element. Don't dec countrequired but increase j.
// When countrequired becomes 0, record it's length as potential answer. Then try to shrink it from left. We will shrink from left but note that countrequired should remain 0. But when we shrink the element at i, it's freq will have to be increased.
// So it's freq in map must be increased by 1. If it's freq becomes greather than 0, it means that we needed that so countrequired is also 1 now. If not, then simply record the new length as potential answer.
// If countrequired is 1 again, so now again start moving j as before.
// Aside from length, also record the i when count becomes 0, so you can actually extract the substring.

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.length();
    map<char, int> mp; // frequency map to store required characters of t
    
    // build the frequency map from string t
    for(char &ch : t) {
        mp[ch]++;
    }
    
    int requiredCount = t.length(); // total characters we still need to match
    int i = 0, j  = 0;              // sliding window boundaries
    int minStart  = 0;              // starting index of the smallest valid window
    int minWindow = INT_MAX;        // length of the smallest valid window
    
    // expand the window by moving j
    while(j < n) {
        char ch_j = s[j];
        
        // if this character was still required, we reduce requiredCount
        if(mp[ch_j] > 0)
            requiredCount--;
        
        // decrease frequency (can go negative if char appears more than needed)
        mp[ch_j]--;
        
        // when all characters are matched (requiredCount == 0), try to shrink
        while(requiredCount == 0) { 
            // check if current window is smaller than the best so far
            if(minWindow > j-i+1) {
                minWindow = j-i+1;
                minStart  = i;
            }
            
            // move i forward to shrink window
            char ch_i = s[i];
            mp[ch_i]++; // put the char back into frequency map
            
            // if after increment, this char becomes "needed" again,
            // we break out since window is no longer valid
            if(mp[ch_i] > 0)
                requiredCount++;
            
            i++; // shrink from the left
        }
        
        j++; // expand window by moving right pointer
    }
    
    // return the smallest valid window substring, or empty if not found
    return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
}

int main() {

}