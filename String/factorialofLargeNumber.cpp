// Problem Statement :- https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

// Let's say you have number 150, and you want to find 150!
// Instead of using the traditional approach, we can store intermediate results, in a string. For eg, first we consider "1" string, then we multiply 150 by 1 and store it again in a string. Now this string have to multiplied with 149 and so on.
// Of course we will have to write multiplication algorithm by ourselves. We will use basic multiplication algorithm, just like how we multiply numbers in Maths.
// But this can be hassle, as intemrediate results are stored in string, and to multiply, we need to take character out one at a time, which is a character which we are trying to multiply with an intger. SO, first we will have to convert this character to an integer. This can become a tedious process.
// To optimize this further, instead of a string, we can use 1D array (string itself is a 1D array) to hold intermediate results. 
// We will increase the array size, as we get more number of digits in intermediate result, as we have to store each digit in a separate index.
// We will store the intermediate result in reverse order. The reason for this is, if we store it in normal order, we can get a carry which will increase the number of digits, and there's no easy way to increase size in left direction (i.e. before 0 index).

#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N) {
    // Step 1: Initialize the result array (ans) with 1, as factorial(0) = factorial(1) = 1
    // This vector will store the digits of the intermediate factorial results in reverse order.
    vector<int> ans(1, 1); // '1' represents the initial factorial value (1)

    // Step 2: Loop to multiply numbers from N down to 2
    // We decrement N in each iteration and multiply the current result with N
    while (N > 1) {
        int carry = 0;  // Initialize carry for each multiplication step
        int res;        // To store the result of multiplication
        int size = ans.size(); // Get the current size of the 'ans' vector (number of digits)

        // Step 3: Multiply each digit in the 'ans' array by N
        // This loop mimics long multiplication where each digit is multiplied by N
        for (int i = 0; i < size; i++) {
            // Multiply the current digit by N and add carry from the previous step
            res = ans[i] * N + carry;
            
            // Store the last digit of the result in the current position of the array
            ans[i] = res % 10;
            
            // Calculate the new carry (the digits to the left of the last digit)
            carry = res / 10; // Carry for the next multiplication
        }

        // Step 4: If there's any carry left after processing all digits, 
        // we need to add it as new digits to the 'ans' vector
        while (carry) {
            // Push back the remainder of carry (i.e., the last digit)
            ans.push_back(carry % 10);
            // Update carry by removing the last digit
            carry /= 10;  // Reduce carry
        }

        // Step 5: Decrease N to process the next number in factorial multiplication
        N--;
    }

    // Step 6: The digits are stored in reverse order, so we need to reverse the array
    // This step is necessary to get the digits of the result in the correct order
    reverse(ans.begin(), ans.end());

    // Step 7: Return the vector containing the digits of the factorial result
    return ans;
}

int main() {
    int N = 150; 
    vector<int> result = factorial(N); 

    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
