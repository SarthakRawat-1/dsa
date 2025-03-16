// Backtracking is a technique used to solve complex problems by exploring all potential solutions incrementally and abandoning solutions as soon as they are determined to be invalid or non-optimal. 
// It's like trying to navigate a maze :- you move forward until you hit a dead end, then go back (or "backtrack") and try a different path.

// Key Aspects :-
// Recursive Exploration :- Backtracking typically uses recursion, where the algorithm explores potential paths one by one.
// Decision-Making and Reversal :- It makes a choice, explores further, and reverses if the path is not promising.
// Problem Constraints :- It uses constraints to eliminate paths, avoiding unnecessary explorations.

// Example Use-Cases :-
// Permutations :- Generating all permutations of a set by fixing elements in positions and backtracking to explore others.
// N-Queens Problem :- Placing queens on a chessboard without conflicts by backtracking when a placement leads to a conflict.

// Backtracking is often used when we need all possible solutions or the most optimal path, especially when using greedy algorithms or dynamic programming is not feasible.