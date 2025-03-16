// Problem Statement :- https://leetcode.com/problems/add-strings/description/

// Knowing this is extremely helpful especially in cases of very large numbers when even long long int can't store the numbers. In that case, we use strings to store numbers.
// Solcing this requires knowing fundamental mathematics. For eg :- Let's say we had to 258 + 94, First we add 8 and 4, which gives us 2 as result and 1 as carry. Now we do 5 + 9 with additional carry 1, this gives us 5 as result and again 1 as carry. And finally 2 + 0 with 1 as carry which gives us 3 as result.
// But there is a problem, we can't just directly take the digit and add them as they are characters, so their ASCII value will be added. We won't get the correct result. So what we will do first is that when we take a character from either of string we will first subtract '0' from that, like '8' - '0' which will give us 8, then this can be added to '2' - '0' which will give us 2 and it'll give the same result as 8 + 2 which is 10. Carry can be stored in a variable.
// There is still one problem, if both strings digits doesn't have same number of digits, then one string will get exhausted earlier and we will have calculate the remaining part in other string. This we can easilyy solve, by using another function to call that function where our addition logic is being implemented. We will always take first of the element to be larger.
// For addition logic, use pointers starting from end of both numbers, add the digits (first convert char to int by subtracting '0' from them) and the carry. Then update carry by dividing sum by 10. After this just append the sum digit (first convert from int to char by adding '0') without carry to the ans string. Do this till the smaller number gets exhausted.
// Once smaller number is exhausted, append the rest of digits from larger number to ans string while keeping in mind the carry. Do this till larger number is exhausted.
// In the end if there'ss till a carry left append it to the ans string. Eg :- 999 + 1, First 9 + 1 = 0, carry = 1, then 9 only but carry = 1 so again, sum = 0 carry = 1 and finally again only 9 but carry = 1, so sum = 0 and carry = 1, but now the larger number has also exhausted. So just append 1 to the ans string to take care of the carry left at end.
// Now, since we are appending the sum of digits, and we are calculating the sum from the end digit. Appending is always done on the right. so, we will have to reverse the string in the end to get the correct answer.

#include <bits/stdc++.h>
using namespace std;

string add(string num1, string num2) {
    // Due to how we have passed the parameters in add function inside the addStrings function, here in this function, num1 will be the bigger string.

    string ans; // To store the result of addition.
    int index1 = num1.size() - 1; // Pointing to last index of num1
    int index2 = num2.size() - 1; // Pointing to last index of num2
    int sum; // To store the result of sum of digits
    int carry = 0; // To store the carry

    // Loop to calculate resulting ans when digits are avaliable in both num1 and num2.
    while (index2 >= 0) { // Since index2 points to last digit of smaller number it'll exhaust first, so sum digits till num2 exhausts.
        sum = (num1[index1] - '0') + (num2[index2] - '0') + carry; // Add the digits, starting from last ofc, and also add the carry. Initially, carry will be zero.
        carry = sum/10; // First update carry

        char c = '0' + sum % 10; // We don't want to insert the entire sum, as first digit of it'll go to carry. Eg :- 9 + 9 = 18, so carry = 18 and we need to append 8 to ans, which is 18 % 10. We have to add '0' to convert int to a character. 
        ans += c; // Update the ans string
        
        // Upon adding the digits, go to the next digit.
        index2--;
        index1--;
    }

    // Digits in num2 has exhausted. Remaining num1 digits with carry we have to add in our and string
     while (index1 >= 0) { 
        sum = (num1[index1] - '0') + carry; 
        carry = sum/10; 

        char c = '0' + sum % 10; 
        ans += c; 

        index1--;
    }

    if (carry) { // If carry still exists after exhuasting both elements, add 1 to the ans string. 1 because we know in this case carry can't be greater than 1, as even 9 + 9 = 18 has 1 as carry.
        ans += '1';
    }

    // Now at the end, we need to reverse the string to get our final answer. This is because we started calculating sum from the last digits and then keep appending it. Appending means element comes to right instead of left, like we do in normal maths addition.
    reverse(ans.begin(), ans.end());

    return ans;
}

string addStrings(string num1, string num2) {
    if (num1.size() < num2.size()) {
        return add(num2, num1); // We call the function, with first parameter as the string which is longer.
    }
    else {
        return add(num1, num2); // Same here.
    }
}

int main() {
    string num1 = "15";
    string num2 = "30";

    cout << "Addition of both digits results in :- " << addStrings(num1, num2) << endl;

    return 0;
}