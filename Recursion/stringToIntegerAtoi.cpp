// Problem Statement :- https://leetcode.com/problems/string-to-integer-atoi/description/

#include <climits>   // For INT_MAX and INT_MIN
#include <string>    // For string operations
#include <iostream>  // For cout

using namespace std;

/*
Approach:
This solution implements a recursive state machine to parse the string according to the myAtoi requirements.
Key steps:
1. Whitespace Handling: Skip leading spaces
2. Sign Handling: Check for optional '+'/'-'
3. Leading Zero Handling: Ignore zeros before digits
4. Digit Conversion: Accumulate valid digits while checking overflow
5. Clamping: Ensure result stays within 32-bit integer range

Edge Cases to Handle:
- Leading/trailing whitespace
- Multiple leading zeros after sign (e.g., "-0042")
- Overflow/underflow beyond 32-bit limits
- Signs followed by non-digits (e.g., "+-12" → 0)
- Non-digit characters interrupting digits (e.g., "123a45" → 123)
- Empty string or whitespace-only input
- Combinations of sign and zeros (e.g., "-0000" → 0)
*/

class Solution {
public:
    int myAtoi(string s) {
        // Start recursion with:
        // - index 0 (beginning of string)
        // - default positive sign
        // - state 0 (whitespace processing)
        // - 0 accumulated value
        return helper(s, 0, 1, 0, 0);
    }

private:
    // Recursive helper function with state management
    // Parameters:
    // - index: current character position
    // - sign: 1 or -1 (multiplier for final value)
    // - state: current processing state (0-3)
    // - acc: accumulated numeric value
    long helper(const string& s, int index, int sign, int state, long acc) {
        // Base case: end of string reached
        if (index >= s.size()) {
            return clamp(sign * acc);
        }

        char c = s[index];
        
        // State machine implementation
        switch (state) {
            case 0: // State 0: Processing leading whitespace
                if (c == ' ') {
                    // Continue skipping whitespace
                    return helper(s, index + 1, sign, 0, acc);
                } else {
                    // Transition from whitespace handling
                    if (c == '+' || c == '-') {
                        // Handle sign character
                        int new_sign = (c == '-') ? -1 : 1;
                        // Move to state 1 (post-sign processing)
                        return helper(s, index + 1, new_sign, 1, acc);
                    } else {
                        // Non-sign character found, process as digit/zero
                        return helper(s, index, sign, 2, acc);
                    }
                }
                break;

            case 1: // State 1: Sign processed, check next character
                if (c == '0') {
                    // Skip leading zero after sign
                    return helper(s, index + 1, sign, 2, acc);
                } else if (isdigit(c)) {
                    // First non-zero digit found
                    long new_acc = c - '0';
                    // Move to state 3 (digit accumulation)
                    return helper(s, index + 1, sign, 3, new_acc);
                } else {
                    // Invalid character after sign
                    return 0;
                }
                break;

            case 2: // State 2: Processing leading zeros
                if (c == '0') {
                    // Continue skipping zeros
                    return helper(s, index + 1, sign, 2, acc);
                } else if (isdigit(c)) {
                    // First non-zero digit found
                    long new_acc = c - '0';
                    // Move to state 3 (digit accumulation)
                    return helper(s, index + 1, sign, 3, new_acc);
                } else {
                    // Non-digit found after zeros
                    return 0;
                }
                break;

            case 3: // State 3: Accumulating digits
                if (isdigit(c)) {
                    // Add digit to accumulator
                    long new_acc = acc * 10 + (c - '0');
                    
                    // Overflow check (prevent recursion depth from growing too much)
                    if (sign == 1 && new_acc > INT_MAX) {
                        return INT_MAX;
                    } 
                    // Underflow check (special case for INT_MIN)
                    else if (sign == -1 && new_acc > static_cast<long>(INT_MAX) + 1) {
                        return INT_MIN;
                    } else {
                        // Continue accumulating digits
                        return helper(s, index + 1, sign, 3, new_acc);
                    }
                } else {
                    // Non-digit character encountered, terminate conversion
                    return clamp(sign * acc);
                }
                break;

            default:
                return 0; // Invalid state
        }
    }

    // Clamp final value to 32-bit integer range
    int clamp(long value) {
        if (value > INT_MAX) {
            return INT_MAX;
        } else if (value < INT_MIN) {
            return INT_MIN;
        } else {
            return static_cast<int>(value);
        }
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Basic conversion
    cout << "Test 1: \"42\"\n";
    cout << "Expected: 42, Actual: " << sol.myAtoi("42") << "\n\n";
    
    return 0;
}

/*
Key Implementation Details:
1. State Transitions:
   0 → 1: When sign is found after whitespace
   0 → 2: When digit found after whitespace
   1 → 2: When zero found after sign
   1 → 3: When digit found after sign
   2 → 3: When non-zero digit found after zeros
   (State 3 stays in state 3 while digits continue)

2. Overflow Prevention:
   - Checks during digit accumulation (state 3)
   - Uses long type for intermediate calculations
   - Special handling for INT_MIN (-2147483648 vs 2147483647)

3. Termination Conditions:
   - Non-digit character in state 3
   - End of string
   - Overflow detected

4. Edge Case Handling:
   - Returns 0 immediately for invalid post-sign characters
   - Handles "-0" and similar cases correctly
   - Properly ignores leading zeros in final calculation
*/