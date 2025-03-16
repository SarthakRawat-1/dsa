// Problem Statement :- https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m

// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

// Power exponential method to compute base^exp.
// This function is used to calculate the value of `base` raised to the power of `exp`.
// It uses a fast exponentiation method which works in O(log exp) time.
long long func(int base, int exp) {
    long long ans = 1;  // Initialize answer to 1 (since any number to the power 0 is 1).
    long long b = base; // Store the base as long long to handle large values.
    
    // Loop until the exponent becomes 0.
    while (exp > 0) {
        if (exp % 2) {
            // If the exponent is odd, multiply the answer with the current base.
            ans = ans * b;
            exp--; // Reduce exponent by 1 to make it even.
        } else {
            // If the exponent is even, square the base and halve the exponent.
            b = b * b;
            exp /= 2; // Halve the exponent.
        }
    }
    return ans; // Return the computed power (base^exp).

    // We could have even implemented this by multiplying base repeatedly by itself till the exponent is there.
    // But to optimize this we are using Exponentiation by Squaring. Here's how it works :- 
    // If the exponent (exp) is odd, you can temporarily reduce the exponent by 1 to make it even (since multiplying by an extra base when exp is odd gives the correct result later).
    // When the exponent is even, you can square the base and halve the exponent. This reduces the exponent much faster than just decreasing it by 1
}

// Function to find the Nth root of m.
// This uses linear search on the possible values of the root to check if any 
// integer value raised to the power `n` equals `m`.
int NthRoot(int n, int m) {
    // Use linear search over all possible integers from 1 to m.
    // For each integer, check if its nth power equals m.
    for (int i = 1; i <= m; i++) {
        long long val = func(i, n); // Calculate i^n using the helper function `func`.

        // If the nth power of i is exactly m, then i is the Nth root of m.
        if (val == m * 1ll) return i;
        // If i^n exceeds m, break the loop since all subsequent values will be larger.
        else if (val > m * 1ll) break;
    }
    
    // If no integer nth root was found, return -1.
    return -1;
}

int main()
{
    int n = 3, m = 27;

    int ans = NthRoot(n, m);

    cout << "The answer is: " << ans << "\n";
    
    return 0;
}


// Optimal Approach :- We know that the answer will lie between 1 and m. So take start = 1 and end = m. Find mid, check if mid is the required number.
// If result of exponentiation on mid is greater than m, then answer must lie in left half of array. 
// If result of exponentiation on mid is less than m, then answer must lie in right half of array.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate mid^n and compare with m.
// Return 1 if mid^n == m, 0 if mid^n < m, and 2 if mid^n > m.
int func(int mid, int n, int m) {
    long long ans = 1;  // Initialize result as 1 (since any number raised to the power of 0 is 1).
    
    // Loop through to calculate mid raised to the power of n
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;  // Multiply ans by mid on each iteration to simulate mid^n.
        
        // If at any point, the result exceeds m, return 2 (indicating mid^n > m).
        if (ans > m) return 2;
    }
    
    // If after the loop, ans is exactly equal to m, return 1 (mid^n == m).
    if (ans == m) return 1;
    
    // Otherwise, return 0 (mid^n < m).
    return 0;
}

int NthRoot(int n, int m) {
    // We will perform a binary search in the range [1, m].
    int low = 1, high = m;

    // Continue binary search until low exceeds high.
    while (low <= high) {
        // Calculate the middle value between low and high.
        int mid = (low + high) / 2;
        
        // Call func() to check whether mid^n equals, is less than, or greater than m.
        int midN = func(mid, n, m);

        // If func returns 1, it means mid^n == m, so mid is the Nth root of m.
        if (midN == 1) {
            return mid;
        }
        // If func returns 0, it means mid^n < m, so we need to search in the higher half.
        else if (midN == 0) low = mid + 1;
        // If func returns 2, it means mid^n > m, so we need to search in the lower half.
        else high = mid - 1;
    }

    // If no exact match is found, return -1 (indicating no integer root exists).
    return -1;
}

int main() {
    int n = 3, m = 27;

    int ans = NthRoot(n, m);

    cout << "The answer is: " << ans << "\n";
    return 0;
}
