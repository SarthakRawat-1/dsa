// Problem Statement :- https://leetcode.com/problems/closest-prime-numbers-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- Using Sieve of Eratosthenes
// Helper function to generate a sieve for prime checking.
// This function returns a boolean vector "isPrime" of size (right + 1) where:
//   isPrime[i] is true if 'i' is a prime number, false otherwise.
vector<bool> sieveHelper(int right) {
    // Initialize a vector with all elements as true.
    // Index represents the number, and the boolean value represents whether it is prime.
    vector<bool> isPrime(right + 1, true);

    // 0 and 1 are not prime numbers.
    isPrime[0] = false;
    isPrime[1] = false;

    // Loop from 2 to sqrt(right) to mark multiples as non-prime.
    // We only need to iterate until i*i <= right.
    for (int i = 2; i * i <= right; i++) {
        // If i is still marked as prime, mark all multiples of i as not prime.
        if (isPrime[i] == true) {
            // Start marking from i * 2 up to right.
            // j is used as a multiplier so that i * j gives all multiples of i.
            for (int j = 2; i * j <= right; j++) {
                isPrime[i * j] = false;
            }
        }
    }

    // Return the sieve, now populated with prime status for each index.
    return isPrime;
}

// Function to find the two closest primes within the range [left, right].
// It first generates all prime numbers in the range using the sieve,
// then iterates through them to find the pair with the smallest difference.
vector<int> closestPrimes(int left, int right) {
    // Generate a boolean vector where each index tells whether it's a prime.
    vector<bool> isPrime = sieveHelper(right);

    // Collect all primes in the range [left, right] into a vector.
    vector<int> primes;
    for (int num = left; num <= right; num++) {
        if (isPrime[num] == true) {
            primes.push_back(num);
        }
    }

    // Initialize the minimum difference with the maximum possible value.
    int minDiff = INT_MAX;
    // The result vector is initialized with {-1, -1} to indicate "no valid pair" by default.
    vector<int> result = { -1, -1 };

    // Iterate over the list of primes and check consecutive pairs.
    for (int i = 1; i < primes.size(); i++) {
        int diff = primes[i] - primes[i - 1];

        // If the current difference is smaller than the smallest found so far,
        // update the minDiff and store the pair.
        if (diff < minDiff) {
            minDiff = diff;
            result = { primes[i - 1], primes[i] };
        }
    }

    // Return the closest pair of primes. If no such pair exists, result remains {-1, -1}.
    return result;
}

// Approach 2 :- Using Trial Division
// Function to check if a given number is prime.
// This function returns false if the number is 1 or divisible by any number between 2 and sqrt(num).
// bool isPrime(int num) {
//     // 1 is not a prime number.
//     if (num == 1) { 
//         return false;
//     }
//     // Check divisibility from 2 to the square root of num.
//     for (int div = 2; div * div <= num; div++) {
//         // If num is divisible by any number, it is not prime.
//         if (num % div == 0) {
//             return false;
//         }
//     }
//     // If no divisors are found, num is prime.
//     return true;
// }

// // Function to find the two closest primes within the range [left, right].
// // It iterates through the range, checking each number for primality using trial division.
// // An early return is performed if the gap between consecutive primes is <= 2,
// // since this is likely the smallest possible gap.
// vector<int> closestPrimes(int left, int right) {
//     // Vector to store all found prime numbers.
//     vector<int> primes;

//     // Iterate over the range [left, right] to check each number.
//     for (int num = left; num <= right; num++) {
//         // Check if the current number is prime.
//         if (isPrime(num) == true) {
//             // If the primes vector is not empty and the difference between the current prime
//             // and the last found prime is 2 or less, return this pair immediately.
//             // This early return optimizes the search for the smallest gap.
//             if (!primes.empty() && num - primes.back() <= 2) {
//                 return { primes.back(), num };
//             }
//             // Add the current prime number to the list.
//             primes.push_back(num);
//         }
//     }

//     // Initialize the minimum difference with the maximum possible value.
//     int minDiff = INT_MAX;
//     // Initialize result vector with default values.
//     vector<int> result = { -1, -1 };

//     // Iterate through the stored primes to find the pair with the minimum difference.
//     for (int i = 1; i < primes.size(); i++) {
//         int diff = primes[i] - primes[i - 1];
//         // If a smaller difference is found, update the minimum difference and the result pair.
//         if (diff < minDiff) {
//             minDiff = diff;
//             result = { primes[i - 1], primes[i] };
//         }
//     }

//     // Return the pair of closest primes. If no such pair exists, result remains {-1, -1}.
//     return result;
// }

int main() {
    int left = 10, right = 19;
    vector<int> result = closestPrimes(left, right);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;   
}