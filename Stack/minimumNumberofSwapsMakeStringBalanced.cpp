// Problem Statement :- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

// We want to ignore the balanced ones and don't swap them. So in a sense, we can just remove balanced parenthesis from the string. Then in remaining, apply the formula :- Swaps = (Number of opening parenthesis brackets + 1)/2
// This formula works because after removing balanced brackets you will always get a pattern like :- ]]]][[[[ And for 1 swap, we will actually make 2 balanced parenthesis pairs. + 1 is to handle odd number of opening brackets, as in this case, we will have one combination left at end, so we need one more swap for that.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum number of swaps required to make the string balanced
int minSwaps(string s) {
    // Stack to keep track of unmatched opening brackets '['
    stack<char> st;

    // Iterate through each character in the string
    for (char &ch : s) {
        if (ch == '[') {
            // If it's an opening bracket, push it onto the stack
            st.push(ch);
        } else if (!st.empty()) {
            // If it's a closing bracket ']' and there is an unmatched opening bracket on the stack
            // pop the top of the stack to match the brackets
            st.pop();
        }
        // If the stack is empty and it's a closing bracket, we ignore it since it can't be balanced.
    }

    // After the loop, the stack will contain unmatched opening brackets only
    // Apply the formula to calculate the minimum number of swaps:
    // The size of the stack indicates the number of unmatched opening brackets
    // To balance the string, we need (unmatched opening brackets + 1) / 2 swaps
    return (st.size() + 1) / 2;
}

int main() {
    string str = "[]][][";
    cout << "Minimum swaps required: " << minSwaps(str) << endl;
    return 0;
}


// You need not use a Stack here as we only require the size of Stack for our answer, so you can just use a counter variable.
