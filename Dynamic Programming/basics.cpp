// Dynamic Programming (DP) is a method for solving problems by breaking them down into smaller, overlapping subproblems and solving each subproblem only once, storing its solution for future use (memoization).

// Dynamic Programming is basically Enhanced Recursion. We can store intermediate recursion results, so as to avoid calculating them again and again.

// In questions related to DP, we will be given a choice. For eg, say we have a knapsack, we will have a choice to add elements to knapsack or not.
// This actually is a pattern related to recursion. If we find recursion with overlapping, it becomes a DP problem.

// An overlapping subproblem is a characteristic of a problem where the same subproblem is solved multiple times during the course of computation.
// This is why dynamic programming works well for these problems because we can store and reuse results (memoization or tabulation).

// In divide and conquer problems (e.g., merge sort), subproblems are usually independent, meaning each subproblem is solved only once, so there are no overlapping subproblems.

// A simple way to deduce an overlapping problem is if the recursive function is calling itself twice or more times, then this is likely an overlapping problem.

// Another identification for DP problems is that we are asked optimal things like min, max, largest etc.

// To approach a DP problem, first try to write recursive solution for the problem. Then use memoization, and then if needed, use Top down DP.
// For quite famous problems and their variation, you can directly use top down approach.


// Memoization is a technique to store the results of expensive function calls and reuse them when the same inputs occur again, avoiding redundant computations.
// Top-Down DP is a style of implementing dynamic programming where the problem is solved recursively, breaking it down into smaller subproblems, and using memoization to avoid redundant computations.
// Tabulation is a dynamic programming approach that solves problems iteratively by building solutions for all subproblems starting from the smallest subproblem (base cases) and progressing to the desired problem (final state).
// Space optimization in dynamic programming refers to reducing the memory usage by eliminating unnecessary storage of intermediate results. Instead of storing the entire table, we only keep the minimum state needed to compute the final result.
