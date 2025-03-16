// Problem Statement :- https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

// Brute Force :- Find all prefix and fuffix and compare which ones are equal. Maximum length of them will be our answer.

// A better approach would be using Two Pointers. Consider :- ABCABDEABC We know that prefix will always start from A, so suffix should also start from A. Hence, tale first pointer at first element of string which is A and second pointer take at the next A. Both are equal, move both by 1 and compare again, B and B are also equal. Move both by 1, compare C and D are not equal. 
// So reset first pointer back to first element and second pointer moves to the next occurence of A (third last element). Again keep comparing, you will find all 3 elements to be same. length is 3.
// Consider :- AAAAAD first pointer to first A, second pointer to second A. Again, keep comparing and it will come not equal at the last element D. Now again, reset first to first A and second to third A. Keep comparing. You will notice that even this approach takes quite a lot of time to deduce that there can't be a common prefix and suffix.

// Optimal Approach :- Consider you have :- ABCDEABCD, First make an array/vector of the same size. This is the LPS table. This will store the number, where it will tell the length of longest prefix/suffix at that index.
// For eg :- Considering the above string, take only A, as prefix and suffix can't take the entire string. There is no prefix and suffix, hence the table/vector/array at index 0 will store 0.
// Now take AB, prefix = A and suffix = B, not equal so table/vector/array at index 1 will store 0. Similarly, for ABC, index 2 will store 0 as A is not equal to C and also AB is not equal to BC.
// Taking ABCD also, index 3 will store 0. ABCDE, index 4 also stores 0. But now ABCDEA, A (at beginning) and A (at end) are equal. rest there are no equal prefix and suffix, so length = 1, index 5 will store 1.
// Taking ABCDEAB, longest common prefix and suffix is AB (length = 2). Index 6 will store 2. ABCDEABC, longest common prefix suffix is ABC, index 7 will store 3. For ABCDEABCD, longest common prefix suffix is ABCD, index 8 will store 4.
// So, our table for this string is :- {0, 0, 0, 0, 0, 1, 2, 3, 4} After we get this table, the element at last index (here 4) will be our answer.
// These elements, say n, will say, that from this index, the n number of characters (in string) before us (including that ofc) are equal to the n number of characters from the beginning of string. Eg :- That 4 shows that ABCD (last 4 characters) are equal to ABCD (first 4 characters). It can also be thought of as the last 4 characters are equal to characters before 4th index (i.e. 0, 1, 2 and 3 index).

// Now consider :- ABCABDABCABCABD For this, we can easily find that our Table becomes :- {0, 0, 0, 1, 2, 0, 1, 2, 3, 4, 5, 3, 4, 5, 6} So for our case, the last element is 6. Hence, ans = 6.

// But how do we fill this table? 
// Again consider :- ABCABDABCABCABD
// Initialize index 0 with 0. Take two pointers, prefix at index 0 and suffix at index 1. Compare if element at prefix and suffix are equal? They are not in our eg, so just fill index 1 with 0. Move suffix to index 2. Again prefix is not equal to suffix, so fill index 2 with 0.
// Now, when prefix at index 0 and suffix at index 3, both are A i.e. they are equal. So store 1 at index 3. Increase both prefix and suffix by 1. B and B are also matching and A and A were already matching. So store 2 at index 4. But how are we getting this 2? It's simply prefix + 1, so 1 + 1 = 2. For that 1 in index 3, it was also 0 + 1 = 1
// Again, increase both by 1, prefix points to index 2 and suffix points to index 5. C and D are not equal. Reset prefix to 0, store 0 at index 5. Increase suffix by 1. A and A are matching again, so store 1 in index 6. Move both pointer by 1. B and B also matching, so store 2 at index 7. Increase both pointer by 1, again C and C matching, so store 3 at index 8, similarly 4 will be stored at index 9 and 5 will be stored at 5.
// But now D (index 5) and C (index 11) are not matching. This time we can't directly write 0 here like we did for index 5. 
// Hence, now we will cahnge our logic a bit. Now, search for C before index 5 by decreasing the prefix pointer. We will find it at index 2. Now however, match index 1 with index 10 (both are equal), so decrease both again, match index 0 with index 9 (both are equal again). Index 0 was the last element. So length = 3 (store it at index 11) , as 3 were matched.
// Similar logic we will use for our D at index 5, when we encountered it. You will see that as there was no D, before that, so still 0 will be stored at index 5.

// Optimized Approach to find 3 for index 11 (and other such cases) :- We know that D and C were different. But if we considered the substring after prefix pointer (after index 5 till C) and before that (index 0 to index 5). We were getting ABCABD and ABCABC, D and C are not common, so forget them for now. ABCAB (prefix, say s1) and ABCAB (suffix, say s2), start prefix from beginning and suffix from end, we can see AB and AB are the only common ones (as ABC and CAB are different). In prefix after AB we have C. And we also wanted to match C in suffix. So length = 3
// So, Longest Prefix of s1 should be equal to Longest Suffix of S2 (ABCAB can't be longest because it's the entire string). If we find this, we can just do their length + 1 (in our eg 2 + 1). But how do we find their longest prefix and suffix? We know that ABCAB and ABCAB are equal. So just take one of these, ABCAB, now find out what is their Longest Prefix Suffix at this point (at last B). This will also give answer 2 as index 4 has stored 2. This 2 will tell us go to 2nd index (as AB before index 2 is equal to AB before index 11) and we can check if it is equal to 11 index. Which it is, so we store 2 + 1 = 3 in index 11.
// If let's say we had F instead at index 11. Now when we reached index 2, it has C, which is also not equal to F. So, go one index back, we arrive at index 1. It has stored 0, so go to index 0, it has A, which is not equal to F, so store 0 in this case.
// This also works for D (index 5) case. As, we have ABC and ABD there. So, AB (s1) and AB (s2), longest common prefix length = 0
// This looking at element previous than prefix and hopping to index indicated by it's stored element value, you have to do this everytime prefix element and suffix element are not equal.

// After this, our prefix reached index 2 and suffix stayed at index 11 (as we just compared them). They were equal, we stored 3 in index 11. Increase both by 1. A and A are also equal, so store 4 at index 12. Increase both by 1, B and B are equal, store 5 at index 13, and simialrly 6 at index 14. This will be our answer.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the longest prefix which is also a suffix
int lps(string s) {
    // Initialize a vector to store the lengths of the longest prefix suffix at each index
    vector <int> lps(s.size(), 0); 
    
    // 'pre' is the prefix pointer, starts at index 0
    // 'suf' is the suffix pointer, starts at index 1
    int pre = 0, suf = 1;

    // Loop until the suffix pointer reaches the end of the string
    while (suf < s.size()) {
        
        // If characters at 'pre' and 'suf' match, we increment both pointers
        // and set the lps value for 'suf' index to 'pre + 1'
        if (s[pre] == s[suf]) {
            lps[suf] = pre + 1;  // Update the LPS value
            suf++;               // Move to the next character in the string
            pre++;               // Move the prefix pointer forward
        } 
        // If characters don't match
        else {
            // If 'pre' is at the starting position (0), there is no common prefix,
            // so set lps[suf] to 0 and move to the next suffix
            if (pre == 0) {
                lps[suf] = 0;
                suf++;
            } 
            // If 'pre' is not 0, reset 'pre' to the previous LPS value (lps[pre - 1])
            // This helps avoid redundant comparisons by jumping back to the earlier valid prefix
            else {
                pre = lps[pre - 1];
            }
        }
    }

    // Return the value at the last index of the LPS array, which gives the longest prefix-suffix length
    return lps[s.size() - 1];
}

int main() {
    string s = "ABABDABACDABABCABAB";

    cout << "Longest Prefix Suffix :- " << lps(s) << endl;
}
