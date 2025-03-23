// Problem Statement :- https://leetcode.com/problems/separate-black-and-white-balls/?envType=daily-question&envId=2024-10-15

// Say, you have s = "10" 
// We have to move 0 to left and 1 to right. Starting from zero index, we see it's 1 and we move to first index, it is 0. Now, we got to know that before this 0, we have seen 1 appear one times. But 0 has to come on left side. There can't be any 1 to the left of any 0. So, we need one swap here.
// Now, say you have :- s = "110"
// Before the 0, we have seen 1 two times, so we will have to move 0 to left 2 times. Hence, 2 swaps.
// Finally, we have :- s = "1101"
// Before the 0 we have seen 1 two times, so we will have to move 0 to left 2 times. Hence, 2 swaps.
// Hence, whenever we encounter a zero, we need to know the number of 1 before that. That is how many swaps, it'll require for that 0.
// For eg :- s = "11010"
// For this case, the first 0 requires 2 swaps and the second 0 requires 3 swaps. So total 5 swaps.

// You can solve this problem even by traversing from right to left. Just note that you have to put black balls to the right, so in this case, you will have to count the number of 0 after every 1.

#include <bits/stdc++.h>
using namespace std;

long long minimumSteps(string s) {
    int n = s.length();  

    long long swap = 0;  
    int black = 0;  // Counter to keep track of the number of '1's (black balls) encountered so far.

    // Traverse the string from left to right.
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {  // When we encounter a '0' (white ball):
            // The number of swaps required is equal to the number of '1's (black balls) seen so far
            swap += black;
        } else {  // When we encounter a '1' (black ball):
            // Increment the count of black balls 
            black++;
        }
    }

    // Return the total number of swaps needed to separate all '0's to the left and '1's to the right.
    return swap;
}

int main() {
    string s = "1010101000101111";

    cout << "Minimum Steps :- " << minimumSteps(s) << endl;

    return 0;
}