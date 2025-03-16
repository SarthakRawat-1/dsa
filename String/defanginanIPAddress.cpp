// Problem Statement :- https://leetcode.com/problems/defanging-an-ip-address/description/

// This is quite a basic problem. We can just make a new string and just iterate over the IP address, then add [.] where . is, and rest of the elements will be added normally.
#include <bits/stdc++.h>
using namespace std;

// Function to defang an IP address by replacing '.' with '[.]'
string defangIPaddr(string address) {
    string ans = "";  // Initialize an empty string to store the result
    
    // Loop through each character in the input string 'address'
    for (int i = 0; i < address.size(); i++) {
        // Check if the current character is a dot '.'
        if (address[i] == '.') {
            // If it is, append "[.]" to the result string 'ans'
            ans += "[.]";
        } else {
            // If it's not a dot, append the current character as is
            ans += address[i];
        }
    }
    // Return the modified string with all '.' replaced by '[.]'
    return ans;
}

int main() {
    string address = "1.1.1.1";
    cout << defangIPaddr(address) << endl;
    return 0;
}