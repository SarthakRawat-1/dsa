// Problem Statement :- https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/description/?envType=daily-question&envId=2025-06-17

// The constraints are way bigger for a recursion backtracking problem.
// We will have to use Combinatorics.
// We know for n element size, we can make n - 1 adjacent pairs. But we have to make exactly k pairs which are equal.
// So, we can see that (n - 1)C(k) pairs are possible.
// Now for every pair, the first element has m ways of filling but the second element has only 1 way of filling it (as both are equal). 
// Hence, we have m ways of creating a pair. Now for the next pair just after it, we will have to choose a different number than the previous selected otehrwise 4 elements consecutively will be the same.
// So we have to select m - 1 ways of populating the next pair. Similarly, we will have m - 1 ways for the next pair.
// If total digits is odd, then the last element left will also have to follow this condition. For all practical purposes that last digit will also be like a pair as it will also have m - 1 ways.
// Total ways to fill array :- m * (m - 1) * (m - 1) * (m - 1)...
// On observation, we will notice that for our question, (m - 1) should be multiplied n - k - 1 times. This will find all combinations which fills the array in way we want, given the particular pairs to make same.
// Now simply multiply :- (n - 1)C(k) * m * (m - 1)^(n - k - 1)

// (n - 1)C(k) can be big and (m - 1)^(n - k - 1) can also be big. We have to use modulo with fermat little theorem and binary exponentiation.

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

// Function to compute (a^b) % MOD using binary exponentiation
int findPower(long long a, long long b) {
    if (b == 0)
        return 1;

    long long half = findPower(a, b / 2);
    long long result = (half * half) % MOD;

    if (b % 2 == 1) {
        result = (result * a) % MOD;
    }

    return result;
}

// Function to compute nCr % MOD using Fermat's Little Theorem
// factorial = precomputed factorials
// fermatFact = precomputed inverse factorials using Fermat's theorem
long long nCr(int n, int r, vector<long long>& factorial, vector<long long>& fermatFact) {
    // nCr = n! / ((n-r)! * r!) % MOD
    return factorial[n] * fermatFact[n - r] % MOD * fermatFact[r] % MOD;
}

// Main function to count number of valid arrays
int countGoodArrays(int n, int m, int k) {
    // Precompute factorials up to n
    vector<long long> factorial(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    // Precompute inverse factorials using Fermat's theorem
    vector<long long> fermatFact(n + 1, 1);
    for (int i = 0; i <= n; i++) {
        fermatFact[i] = findPower(factorial[i], MOD - 2); // a^(MOD-2) % MOD
    }

    // Step 1: Choose k positions among n-1 adjacent pairs to be equal → (n-1)Ck
    long long result = nCr(n - 1, k, factorial, fermatFact);

    // Step 2: First element of array has m choices
    result = result * m % MOD;

    // Step 3: For (n - k - 1) positions, pick a different element than previous → (m - 1)^(n - k - 1)
    result = result * findPower(m - 1, n - k - 1) % MOD;

    return result;
}

int main() {
    // Example usage:
    int n = 5;  // length of the array
    int m = 3;  // range of values from 1 to m
    int k = 2;  // number of matching adjacent pairs

    int result = countGoodArrays(n, m, k);
    cout << "Number of valid arrays: " << result << endl;

    return 0;
}
