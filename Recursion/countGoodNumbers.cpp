// Problem Statement :- https://leetcode.com/problems/count-good-numbers/description/

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7; // Modulo value as specified in the problem

/*
Approach:
- A digit string is "good" if digits at even indices (0, 2, 4, ...) are even (0, 2, 4, 6, 8)
  and digits at odd indices (1, 3, 5, ...) are prime (2, 3, 5, 7).
- For a string of length n:
   - The number of even indices is ceil(n/2), computed as (n + 1) / 2 using integer division.
   - The number of odd indices is floor(n/2), computed as n / 2.
- Each even index has 5 possible choices, and each odd index has 4 choices.
- The total number of good strings is (5^even_indices) * (4^odd_indices) modulo 1e9+7.
- To efficiently compute large exponents, we use modular exponentiation (exponentiation by squaring),
  which reduces the time complexity to O(log n).
*/

/**
 * Computes (a^b) % MOD using recursion (exponentiation by squaring).
 * 
 * @param a The base.
 * @param b The exponent.
 * @return (a^b) % MOD.
 */
long long power(long long a, long long b) {
    if (b == 0) return 1; // Base case: any number to the power of 0 is 1
    long long half = power(a, b / 2) % MOD; // Recursively compute a^(b/2)
    long long res = (half * half) % MOD; // Square the result to get a^b (if exponent is even)
    if (b % 2 == 1) res = (res * a) % MOD; // If exponent is odd, multiply by 'a' once more
    return res;
}

/**
 * Calculates the number of good digit strings of length n.
 * 
 * @param n The length of the digit string.
 * @return The count of good strings modulo 1e9+7.
 */
int countGoodNumbers(long long n) {
    // Calculate the number of even and odd positions in the digit string
    long long even_positions = (n + 1) / 2; // Ceiling of n/2 (handles both even and odd n)
    long long odd_positions = n / 2; // Floor of n/2
    
    // Compute the number of choices for even positions (5 options each) using modular exponentiation
    long long even_choices = power(5, even_positions);
    // Compute the number of choices for odd positions (4 options each)
    long long odd_choices = power(4, odd_positions);
    
    // Total combinations is the product of even and odd choices, modulo 1e9+7
    return (even_choices * odd_choices) % MOD;
}

int main() {
    // Example test cases
    cout << countGoodNumbers(1) << endl;   // Output: 5 (all even digits for single position)
    cout << countGoodNumbers(4) << endl;   // Output: 400 (5^2 * 4^2 = 25 * 16 = 400)
    cout << countGoodNumbers(50) << endl;  // Output: 564908303 (handled via modular exponentiation)
    return 0;
}