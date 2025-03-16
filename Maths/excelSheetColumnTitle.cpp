// Problem Statement :- https://leetcode.com/problems/excel-sheet-column-title/description/

// If we have a number 12, we can write it as (1 x 10^1) + (2 x 10^0) and we also know how to extract digits from a number.
// In a similar, way we can treat column names. Difference is that we have numbers from 0 to 9 but letters we have from A - Z.
// But note that when we extract digits using % operator, we will get the digits in reverse order i.e. last digit we will get first. Simialr thing will happen in column name, so we will have to reverse the result in the end.
// How do we convert number to letter? Whatever remainder we get, we add 'A' to it. So 'A' + 1 will give B. But as Excel starts indexing from 1, so A should correspond to 1, instead of B. So, we can do remain + 'A' - 1
// If we get multiple of 26, it's modulo with 26 will give 0, and 0 + 'A' - 1 will give a character before 'A' in ASCII Table, which we don't want.
// To rectify this, we can just subtract 1 from the columnNumber. This way, we can also avoid subtracting 1 in remain + 'A' - 1

#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string result;  // Initialize an empty string to store the final result (column name).

    // Loop until we reduce the columnNumber to 0
    while (columnNumber > 0) {
        columnNumber--;  // Decrease columnNumber by 1 to handle 1-based indexing.

        // Find the remainder when dividing by 26 (this will give us a character from 'A' to 'Z').
        int remain = columnNumber % 26;

        // Convert the remainder to a character. Since 'A' corresponds to 0, we add 'A' to the remainder.
        char ch = remain + 'A';

        // Append the character to the result string.
        result.push_back(ch);

        // Reduce columnNumber by dividing it by 26. This will shift us to the next "digit" in base 26.
        columnNumber /= 26;
    }
    
    // The result is generated in reverse order because we process the least significant "digit" first.
    // We need to reverse the string to get the correct column title.
    reverse(begin(result), end(result));

    return result;  // Return the final column title string.
}

int main() {
    int columnNumber = 28;
    string result = convertToTitle(columnNumber);
    cout << "Column title of " << columnNumber << " is " << result << endl; 
}