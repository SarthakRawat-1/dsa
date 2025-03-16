// Problem Statement :- https://leetcode.com/problems/climbing-stairs/description/

// Let's say n is 5, then the possible ways of climbing stairs includes 1 + 1 + 1 + 1 + 1, 1 + 1 + 1 + 2, 2 + 1 + 1 + 1, 1 + 1 + 2 + 1, 1 + 2 + 1 + 1, 2 + 1 + 2, 2 + 2 + 1, 1 + 2 + 2. Total 8 ways.
// So instead of complicating it, start from n = 1, obv there is only one way to climb. If n = 2, then there are two ways to climb, 1 + 1 and 2. If n = 3, there are now 3 ways to climb, 1 + 1 + 1, 2 + 1, and 2 + 1.
// Now if n = 4, then we have 5 number of ways to climb, 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 2 + 2.   
// Now observe carefully, for n = 3, the answer is 3 which is the sum of 2 and 1 i.e. answers of n = 2 and n = 1. For n = 4, the answer is 5 which is the sum of 3 and 2 i.e. answer of n = 3 and n = 2.
// Similarly, for n = 5 the answer is 8 which is sum of answer of n = 4 and n = 3 i.e. 5 and 3.
// This works because :- Think you have n = 4, now you know that from n = 3, you need to jsut take 1 step to reach n = 4, simialrly from n = 2, you need only 3 steps to reach n = 4. So if you know how many steps we need to take to reach n = 2 and n = 3, we can just add 2 and 1 to all the steps respectively and we will reach n = 4. Remember, we are calcualting total number of ways, not steps, so adding these won't matter in total number of ways. We can just directly add sum of result n = 2 and n = 3. 
// Doubt - But from n = 2, we can also go in two ways one is 2 and other is 1 + 1. We didn't considered 1 + 1. We didn't include this case, when you will trace out all the possibilities of n = 2 and n = 3, you will realize this has already been considered.

#include <iostream>
using namespace std;

// Recursive function to calculate the number of ways to climb n steps
int climbStairs(int n) {
    // Base case 1: If n is 0, there is 1 way to stay at the ground (do nothing)
    if (n == 0) {
        return 1;
    }
    
    // Base case 2: If n is 1, there is only 1 way to climb to the top (a single 1-step)
    if (n == 1) {
        return 1;
    }

    // Could have also declared another base case for n = 2, it also returns 1. But it is redundant.

    // Recursive case: The number of ways to climb n steps is the sum of:
    // 1. The number of ways to climb (n-1) steps and then take a 1-step.
    // 2. The number of ways to climb (n-2) steps and then take a 2-step.
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int n;

    // Input: Asking the user to input the number of steps n
    cout << "Enter the number of steps: ";
    cin >> n;

    // Output: Calling the recursive function and printing the number of ways to climb to the top
    cout << "Number of distinct ways to climb " << n << " steps: " << climbStairs(n) << endl;

    return 0;
}

// Although this solution is correct, Recursion solution will give you a TLE in Leetcode.
// It happens due to redundant calculations. Each recursive call recalculates the number of ways to climb the same number of steps multiple times, leading to an exponential time complexity.

