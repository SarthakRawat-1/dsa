// Problem Statement :- https://leetcode.com/problems/string-compression/description/

// Run Length Encoding Algorithm

// Consider :- {a, a, b, b, c, c, c} Take i initialized to 0. Traverse array using this i, and first find count of char a (store this in a variable called curr_char) using it. Take another variable, say index which we will use to change. Initialized index to 0, we will first put curr_char there and then increase it by 1 and put count of curr_char there. Again, increase index by 1.
// Now both index and i are pointing to index 2. curr_char is b, start finding it's count using i and update values using index. After this index and i are at 4. curr_char is now 4, increasing i you will find it's count 3. index will be used to assign curr_char at index 4 and count at index 5. index will be increased to 6. We need not change the c at index 6 (it is given in the question that compiler will only check till the length you return, and ignore the rest of the array). This index i.e. 6 is our answer.
// Consider :- {a, a, a, a, a, a, a, a, a, a, a, b, b} curr_char = a and count = 10. i will point to second last index. Now we need to use index to assign curr_char at index 0 and count at index 1. but count is 10, so we have to write 1 on index 1 and 0 on index 2. You can do this by converting 10 to string and assign char one by one.
// After this index will point to index 3. i will increase then for curr_char = b and count = 2. Now index variable will be used to store b at index 3 and 2 at index 4. index now points to 5. 5 is our answer.

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    // Step 1: Get the size of the input vector 'chars'
    int n = chars.size(); 

    // 'index' will store the position in the compressed array
    // 'i' is used to traverse through the input characters
    int index = 0;
    int i = 0;

    // Step 2: Traverse the entire array
    while (i < n) {
        // Store the current character to compress
        char curr_char = chars[i];
        int count = 0;

        // Step 3: Count the consecutive occurrences of the current character
        // Keep incrementing 'i' until a different character is found or end of array is reached
        while (i < n && chars[i] == curr_char) {
            count++;  // Increment the count for each matching character
            i++;      // Move to the next character
        }

        // Step 4: Write the current character to the compressed array
        chars[index] = curr_char; 
        index++;  // Move index forward for next character

        // Step 5: If there are more than one occurrence of the character, write the count
        if (count > 1) {
            // Convert the count to a string (as we need to store individual digits)
            string count_str = to_string(count);

            // Write each character of the count to the compressed array
            for (char &c : count_str) {
                chars[index] = c;  // Write the digit
                index++;  // Move index forward for next digit
            }
        }
    }

    // Step 6: Return the length of the compressed array
    return index;
}


int main() {
    vector <char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << "The Length of the compressed string is :- " << compress(chars) << endl;
    return 0;
}