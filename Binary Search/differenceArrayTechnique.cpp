// It is used to efficiently apply range updates, eg :- we have to update from arr[i] to arr[j]. It helps to do multiple updates in constant time.
// Eg :- nums = {0, 0, 0, 0, 0} and query = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}}
// The query {1, 3, 2} is saying that from index 1 to index 3, add 2 to all those values.
// Difference Array Construction :-
// Given an initial array A, you create a difference array D where:
// D[0] = A[0]
// For every other index i (i > 0), D[i] = A[i] - A[i-1]
// Range Updates:
// When you want to add a value X to all elements in a range from index L to R (inclusive), you update the difference array as follows:
// D[L] += X
// If R+1 is within bounds of the array, then D[R+1] -= X
// This way, the addition is effectively "started" at L and "ended" just after R.
// Reconstructing the Updated Array:
// Once all range updates are performed on D, you recover the updated array A' by taking the prefix sum (cumulative sum) of the difference array:
// A'[0] = D[0]
// For each i > 0, A'[i] = A'[i-1] + D[i]

// Suppose you have an array A = [1, 2, 3, 4, 5]. The corresponding difference array D would be:
//     D[0] = 1
//     D[1] = 2 - 1 = 1
//     D[2] = 3 - 2 = 1
//     D[3] = 4 - 3 = 1
//     D[4] = 5 - 4 = 1

// Now, if you want to add 10 to all elements from index 1 to 3:
//     D[1] += 10 → becomes 11
//     D[4] -= 10 (since R+1 = 4) → becomes -9

// The modified difference array becomes:
//     D = [1, 11, 1, 1, -9]

// Taking the prefix sum:
//     A'[0] = 1
//     A'[1] = 1 + 11 = 12
//     A'[2] = 12 + 1 = 13
//     A'[3] = 13 + 1 = 14
//     A'[4] = 14 + (-9) = 5

// Thus, the updated array is A' = [1, 12, 13, 14, 5].

// If multiple range update queries are given, you should first apply all the updates to the difference array and then compute the prefix sum to reconstruct the updated array efficiently.

// If you don't want to calculate difference array like that and instead initialize all elements to zero for it :-
// If you start with a difference array initialized to all zeros and apply range updates, the resulting array (after taking the prefix sum) will represent the net change from the original array (and not the final result). 
// Adding this net change array to the original array will give the final updated values.
// We add because here query is asking for addition. If in question it asks for subtraction, then subtract.