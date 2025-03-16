// Problem Statement :- https://leetcode.com/problems/integer-to-roman/description/

// To convert any number to Roman numerals for eg :- 1248, just write it like 1000 + 200 + 40 + 5 + 3, so now it can be written like MCCXLVIII
// We can predefine the Roman numeral symbols for different values and use a greedy approach to build the numeral for any integer within the given range (1 to 3999).
// For a given number, we will iterate over the values vector and find the number just smaller than that. Then we can append the corresponding symbol to the result and decrease given number by the value. Keep doing this, till the values array is empty, i.e. number becomes zero.


#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num) {
    // Arrays of Roman numeral symbols and their corresponding values
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Result string to store the Roman numeral representation
    string result = "";
    
    // Iterate over all values and their corresponding symbols
    for (int i = 0; i < values.size(); i++) {
        // Append the corresponding Roman numeral symbol as many times as possible
        while (num >= values[i]) {
            result += symbols[i];
            num -= values[i]; // Reduce the number by the value
        }
    }
    
    // Return the resulting Roman numeral string
    return result;
}

int main() {
    int num = 1994;
    cout << intToRoman(num) << endl;  
    return 0;
}

