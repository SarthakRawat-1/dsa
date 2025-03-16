// Problem Statement :- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

// Use a Stack. Initially, Stack is empty. Use a pointer i to traverse the string from beginning. Insert first character in Stack. Move i by 1. Check if this is equal to element at top of Stack. If it is not, then put this also on top of Stack. If it is same, then don't put that element into Stack and also delete the top element of Stack. Keep doing this till you exhaust the String.
// Then, just pull out characters from Stack and add them to answer string and reverse the answer string to get the final answer.

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;
    
    for(int i = 0; i < s.size(); i++) {
        if(st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "abbaca";
    cout << removeDuplicates(s);
}