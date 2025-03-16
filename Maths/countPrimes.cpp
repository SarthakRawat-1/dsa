// Problem Statement :- https://leetcode.com/problems/count-primes/description/

// We will use Sieve of Eratosthenes to check if a number is prime or not.
// Create an array (prime []) of size n + 1 where all elements are initialized to 1 (indicating potential primes). Starting from 2 (the first prime), mark all multiples of 2 as 0 (not prime). Move to the next number (3) and repeat the process: mark all multiples of 3 as 0. Continue this process for each subsequent number (which is prime i.e. not marked 0 when you arrive on that) until n. If a number is already marked as 0, skip it because it's a multiple of a smaller prime.
// Optimization :- Instead of starting at i × 2 for each prime i, start at i × i, because smaller multiples (e.g., i × 2, i × 3) would have already been marked by earlier primes. This reduces redundant marking and improves efficiency.
// After processing, the array will contain 1 for prime numbers and 0 for non-prime numbers.

#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    // Edge case: If n is less than or equal to 2, no prime numbers exist below 2.
    if (n <= 2) return 0;

    // Create an integer array 'prime' of size n. This is because problem is asking for prime numbers that are strictly less than n.
    // Initialize all elements to 1 (assuming all numbers are prime initially).
    vector<int> prime(n, 1);

    // 0 and 1 are not prime numbers.
    prime[0] = prime[1] = 0;

    // Iterate over numbers starting from 2 up to sqrt(n). 
    // Optimization: We only need to mark multiples of numbers up to sqrt(n).
    for (int i = 2; i * i < n; i++) {
        // If 'i' is a prime (i.e., it hasn't been marked as 0 yet).
        if (prime[i]) {
            // Mark all multiples of 'i' starting from i*i as 0 (i.e., not prime).
            // Starting from i*i instead of i*2 because smaller multiples are already marked.
            for (int j = i * i; j < n; j += i) {
                prime[j] = 0;
            }
        }
    }

    // Count the number of primes by checking which entries in the array remain 1.
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i]) count++;
    }

    return count;
}


int main() {
    int n = 100;
    cout << "The number of prime numbers less than or equal to " << n << " is " << countPrimes(n) << endl;
}