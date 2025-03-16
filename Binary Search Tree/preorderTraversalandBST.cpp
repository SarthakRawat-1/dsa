// Problem Statement :- https://www.geeksforgeeks.org/problems/preorder-traversal-and-bst4006/1

// One way is to make BST using the given preorder traversal, and then check if it's preorder is same as the given or not.

// Optimized Method :- Same logic as constructBSTfromPreorder.cpp
// If it completes the Preorder traversal, then a valid BST exists. Here we need not even build the tree as we only have to verify.
// But if you directly use that, it will give Segmentation Fault.
// This sometimes happens with Recursion because Recursion function is allocated memory in Stack.
// But you will see that when we use a data structure like Stack or vector etc. instead of recursion, as they being from STL are allocated memory in Heap and hence can allow larger memory allocation, and hence can solve the question easily.
// So we will use Stack here.

#include <iostream>   // For input/output operations.
#include <stack>      // To use the STL stack container.
#include <climits>    // For INT_MIN and INT_MAX.
using namespace std;

/*
 * Function: canRepresentBST
 * ---------------------------
 * Checks whether the given array (preorder traversal) can represent a valid BST.
 *
 * Parameters:
 * - arr: The array of integers representing the preorder traversal.
 * - N: The number of elements in the array.
 *
 * Returns:
 * - 1 (true) if the array can represent a valid BST.
 * - 0 (false) otherwise.
 *
 * Explanation:
 * - The idea is to simulate the construction of the BST using intervals (ranges) for valid
 *   node values. Instead of using recursion (which may lead to stack overflow for large input),
 *   we use two stacks (lower and upper) to keep track of the valid lower and upper bounds.
 *
 * - Initially, the valid range for the root is [INT_MIN, INT_MAX]. We push these values onto
 *   two stacks, where 'lower' holds the lower bound and 'upper' holds the upper bound.
 *
 * - For every element in the array:
 *   1. If the current element is smaller than the current lower bound (top of the 'lower' stack),
 *      then the preorder cannot represent a valid BST. Return 0.
 *
 *   2. While the current element is greater than the current upper bound (top of the 'upper' stack),
 *      we update our range by popping from both stacks. This simulates backtracking to the parent
 *      node where the current element could be a right child.
 *
 *   3. After determining the correct interval, we pop the top elements from both stacks to get
 *      the current valid interval [lowerBound, upperBound] for insertion.
 *
 *   4. Then, we push two new intervals onto the stacks:
 *      - For the right subtree: the lower bound becomes the current element and the upper bound remains unchanged.
 *      - For the left subtree: the lower bound remains unchanged and the upper bound becomes the current element.
 *
 * - If all elements satisfy the BST property based on the maintained intervals, the function returns 1.
 */
int canRepresentBST(int arr[], int N) {
    // Two stacks to hold the lower and upper bounds for the next node.
    stack<int> lower, upper;

    // Initially, the entire integer range is valid for the root.
    lower.push(INT_MIN);
    upper.push(INT_MAX);

    // Variables to hold the current lower and upper bounds.
    int lowerBound, upperBound;

    // Process each element of the preorder traversal.
    for (int i = 0; i < N; i++) {
        // If the current element is less than the allowed lower bound, it cannot be placed in the BST.
        if (arr[i] < lower.top())
            return 0;

        // If the current element is greater than the allowed upper bound,
        // it means we are done with the left subtree and need to backtrack.
        // Pop the bounds until the current element fits in the current interval.
        while (arr[i] > upper.top()) {
            upper.pop();
            lower.pop();
        }

        // The current top elements of the stacks represent the valid interval for the current node.
        lowerBound = lower.top();
        upperBound = upper.top();

        // Remove the current interval as we will now update it.
        lower.pop();
        upper.pop();

        // For the right subtree:
        // The current element becomes the new lower bound, while the upper bound remains the same.
        lower.push(arr[i]);
        upper.push(upperBound);

        // For the left subtree:
        // The lower bound remains the same, but the current element becomes the new upper bound.
        lower.push(lowerBound);
        upper.push(arr[i]);
    }

    // If we process all elements without any violation, the array represents a valid BST.
    return 1;
}

int main() {
    // ------------------------
    // Example 1:
    // Preorder traversal array that can represent a valid BST.
    // For example: {40, 30, 35, 80, 100}
    // Expected output: 1 (true)
    // ------------------------
    int arr1[] = {40, 30, 35, 80, 100};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Array {40, 30, 35, 80, 100} can represent BST? " << (canRepresentBST(arr1, size1) ? "Yes" : "No") << endl;

    // ------------------------
    // Example 2:
    // Preorder traversal array that cannot represent a valid BST.
    // For example: {40, 30, 35, 20, 80, 100}
    // Expected output: 0 (false)
    // ------------------------
    int arr2[] = {40, 30, 35, 20, 80, 100};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Array {40, 30, 35, 20, 80, 100} can represent BST? " << (canRepresentBST(arr2, size2) ? "Yes" : "No") << endl;

    return 0;
}
