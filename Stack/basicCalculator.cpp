// Problem Statement :- https://leetcode.com/problems/basic-calculator/description/

// We obviously want to iterate over the string. A character in a string can be digit, '+', '-', '(' or ')'. We also need a number variable to store the number which will form with the digits. There will also be sign variable to store '+' (use 1) or '-' (use -1). A result variable to store the final result.
// Consider "10-(4+5+2)-3+(6+8)" Assume sign = 1 in beginning. Starting from i = 0, we got 1, update number to (0 * 10) + 1 = 1. Then we encountered 0, so we have to update number with (number * 10) + (s[i] - '0') (converting char to int). Now we got '-', so we have already made a number, so add number to result (with the sign) and reset number to 0. Now we will update sign with -1.
// Then we encountered (, it means according to BODMAS rule, this should be solved first. Store the previous number value, here 10, in Stack. We want to remember it, because our priority now is to solve the parenthesis first. Also store sign before parenthesis, here -1, in the Stack. Reset result to 0 and sign to 1.
// Then we encountered 4, number = 4. Then we encountered a '+', so add 4 to result (with it's sign), reset number to 0. Now, we have 5, which means number = 5. Then this will add. Continuing this, we will reach ), this will also mean that a number has ended. So, we will add 2 to the result. It also means that Bracket has been solved. So, go back to Stack, retrieve the parenthesis sign (multiply it with result of parenthesis) and the other number (add this to that result).
// Now we got '-', it means number has ended, but there is no number, number is assigned to 0 at this point and it will continue to be 0. But now sign is -1. Then we encountered 3, and then a + (sign, so number is terminating), hence add 3 * sign (-1) to the result. Then store this result and sign of parenthesis = 1, in Stack. Then continue to solve.
// We also have to check for the case, where string is termianting with a digit, as in this case, that digit will be stored in number but never added to the result.

#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a simple arithmetic expression that includes parentheses
int calculate(string s) {
    int n = s.length();  // Get the length of the string
    stack<int> st;       // Stack to store intermediate results and signs

    int number = 0;      // Variable to store the current number being formed
    int result = 0;      // Variable to store the final result of the expression
    int sign = 1;        // Variable to store the current sign (1 for '+', -1 for '-')

    // Loop through each character of the input string
    for (int i = 0; i < n; i++) {
        // If the character is a digit, form the complete number
        if (isdigit(s[i])) {
            // Convert character to integer and form the number
            number = number * 10 + (s[i] - '0');
        }
        // If the character is a '+' sign, process the current number
        else if (s[i] == '+') {
            // Add the current number to the result with its sign
            result += (number * sign);
            // Reset the number and set the sign for the next number
            number = 0;
            sign = 1;  // Set sign to positive for the next number
        }
        // If the character is a '-' sign, process the current number
        else if (s[i] == '-') {
            // Add the current number to the result with its sign
            result += (number * sign);
            // Reset the number and set the sign for the next number
            number = 0;
            sign = -1; // Set sign to negative for the next number
        }
        // If the character is an opening parenthesis '('
        else if (s[i] == '(') {
            // Push the current result and sign onto the stack for later use
            st.push(result);  // Store the result before the parenthesis
            st.push(sign);    // Store the sign before the parenthesis
            // Reset result and sign for the expression inside the parentheses
            result = 0;
            number = 0;  // Clear the number variable as a new expression starts inside the parentheses
            sign = 1;    // Assume the sign is positive inside the parentheses
        }
        // If the character is a closing parenthesis ')'
        else if (s[i] == ')') {
            // Process the current number and add it to the result
            result += (number * sign);
            number = 0;  // Reset the number as we've processed it

            // The expression inside the parentheses is complete, so retrieve the previous sign and result
            int stack_sign = st.top();  // Retrieve the sign before the parentheses
            st.pop();
            int last_result = st.top(); // Retrieve the result before the parentheses
            st.pop();

            // Multiply the current result by the retrieved sign and add the previous result
            result *= stack_sign;
            result += last_result;
        }
    }

    // After the loop, add any remaining number to the result (if the string ends with a number)
    result += (number * sign);

    // Return the final computed result
    return result;
}

int main() {
    string expression = "10-(4+5+2)-3+(6+8)";
    cout << "Result of the expression: " << calculate(expression) << endl;
    return 0;
}
