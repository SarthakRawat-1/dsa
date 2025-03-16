// Problem Statement :- https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

// P refers to pickup, D refers to delivery. For n = 1, only P1 D1 is valid. For n = 2, P2 D2 P1 D1, P2 P1 D2 D1, P2 P1 D1 D2, P1 P2 D2 D1, P1 P2 D1 D2 and P1 D1 P2 D2 are possible so total 6 possibilities.
// Brute Force :- First for any n, make an array of size 2n, then find all possible permutations of that and find which ones are valid by checking if D1 and D2 are coming after P1 and P2 respectively.

// Optimal Approach :- For n = 2, means there are 2 orders. We already know answer when there is only 1 order i.e. P1 D1. Now the second order, we have to adjust in these possible spaces (represented by _) :- _P1_D1_ FIrst, we have decided to fix the space before P1, only P2 can come here and not D2, as other spaces after that. After that, there are 3 possibilities for D2, two in spaces, one where it comes after P2 in the same space. For another case, we fix the space between P1 and D1. We put P2 here, and now there are only 2 possibilities, one in space after that (not before as it violates the P2 before D2 rule) and one in the same space after P2. Simialrly, when we fix space after D1, we put P2 there, only 1 possibility remains. D2 in same space after P2.
// Total number of ways :- 3 + 2 + 1 = 6, We notice that this is nothing but sum of numbers from 1 to total number of spaces.
// But how do we determine the number of spaces? It will be (n - 1) * 2 + 1 For eg :- n = 2 means (2 - 1) * 2 + 1 = 3 spaces
// For n = 3, we can now easily determine that total number of ways should be :- 5 + 4 + 3 + 2 + 1, but this is not entirely correct. This only cosniders one permutation of n = 2, and possibilities for that one permutation, but we have total 6 possibilites for n = 2 itself, and each of them has 5 spaces available. Hence, total number of ways for n = 3 will be 6 * (5 + 4 + 3 + 2 + 1)

#include <bits/stdc++.h>
using namespace std;

int countOrders(int n) {
    if (n == 1) return 1; // If n = 1, then total number of ways will be 1

    long long result = 1; // Intialise result to 1, to store the total number of ways for n = 1

    for (int i = 2; i <= n; i++) { // We have to find answer for n = n, for that we will have to find answers for all n before n = n as well.
        int spaces = (i - 1) * 2 + 1; // Calculate the number of spaces

        int possibilities = spaces * (spaces + 1)/2; // Formula to calculate sum of n natural numbers

        result *= possibilities; // Same Logic as explained above, when I was explaining n = 3
    }

    return result; // For the leetcode problem, you need to return result %1e9+7 instead as it is demanded in the Problem Statement.
}

int main() {
    int n = 3;

    cout << countOrders(n) << endl;
}