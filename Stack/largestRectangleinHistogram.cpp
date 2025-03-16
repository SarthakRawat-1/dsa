// Problem Statement :- https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// Method 1 :- Start from the first element, we already know the height for that, check what can be the maximum breadth for this rectangle. 
// This we can find, by including all those individual rectangles whose height is more than or equal to the current rectangle (to either side of it, but they should be continuos i.e. if we have {2, 1, 3}, then 3 can't contribute in rectangle starting from 2). The breadth we can easily determine, by finding the next smallest element for every rectangle on either side. Then we can simply find the area of this rectangle.
// We will find this for every individual rectangle and take the maximum area out of all of them.
// We can use two separate arrays. One for storing index of next smaller element on left for each rectangle and other for next smaller element on right for each rectangle.
// Maximum width or breadth of rectangle, we can find by (NSE on Right - NSE on Left - 1)

// Method 2 :- We still need NSE on left and NSE on right to solve this. We can find both of them in a single iteration.
// Consider, {2, 3, 4, 2, 6, 1, 4, 5, 3}. We will try to find NSE on right. Starting with 2, we don't know it's NSE on right, so we insert index 0 to stack.
// Similarly for 3, it doesn't know it's NSE on right, and it also can't be the NSE on right for index 0 i.e. 2, so it's index is also inserted into Stack. Similarly, index 2 will also be inserted into Stack.
// Stack :- {0, 1, 2}, we encounter index 3 i.e. 2, which is NSE on right for index 2 i.e. 4. But now, using Common sense on how we are filling the stack, the element just below index 2 in our case at index 1, will be the NSE on left for element at index 2 at 4. We know height and NSE on left and right for the element, so we can find area. Pop index 2 from stack.
// But that 2, can also be NSE on right for element at index 1 i.e. 3. So do the same procedure for it too and pop index 1 from stack. After this, as 2 can't be NSE on right for 2, so insert index 3 in stack also.
// If nothing is present in stack, then for NSE on left, we will use -1.
// Similarly, if we are not able to find NSE on right, then we will use n as NSE on right for remaining stack elements. NSE on left, we will find as usual by looking at element just below in stack.

// NOTE :- This method doesn't return the correct area for a rectangle whose NSE on left was not available in the stack and stack was not empty. However, we are simmply ignoring this, as our final answer still comes correct.
// So this method is good for overall answer, but will give incorrect answer, if wanted to find maximum area of rectangle for each entry.

#include <bits/stdc++.h>
using namespace std;

// Method 1
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(); // Number of bars in the histogram

    // Arrays to store the indices of the Next Smaller Element (NSE) on the right and left
    vector<int> Right(n); // Stores the index of the next smaller element to the right
    vector<int> Left(n);  // Stores the index of the next smaller element to the left

    stack<int> st; // Stack to help find the NSE indices efficiently

    // Step 1: Compute the indices of the next smaller element on the right for each bar
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack until we find an element smaller than the current height
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Right[st.top()] = i; // Update the NSE index for the top of the stack
            st.pop();            // Remove the element from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // If no smaller element exists to the right, set the index to `n` (end of the array)
    while (!st.empty()) {
        Right[st.top()] = n;
        st.pop();
    }

    // Step 2: Compute the indices of the next smaller element on the left for each bar
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until we find an element smaller than the current height
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Left[st.top()] = i; // Update the NSE index for the top of the stack
            st.pop();           // Remove the element from the stack
        }
        st.push(i); // Push the current index onto the stack
    }

    // If no smaller element exists to the left, set the index to `-1` (start of the array)
    while (!st.empty()) {
        Left[st.top()] = -1;
        st.pop();
    }

    int ans = 0; // Variable to store the maximum rectangle area

    // Step 3: Calculate the maximum rectangle area
    for (int i = 0; i < n; i++) {
        // Calculate the width of the rectangle: (Right[i] - Left[i] - 1)
        int width = Right[i] - Left[i] - 1;

        // Calculate the area of the rectangle with height `heights[i]`
        int area = heights[i] * width;

        // Update the maximum area
        ans = max(ans, area);
    }

    return ans; // Return the maximum rectangle area
}

// Method 2
int largestRectangleArea(vector<int>& heights) {
    int ans = 0;       // Variable to store the maximum rectangle area
    int index;         // To store the index of the current height being processed
    stack<int> st;     // Stack to store indices of heights in non-decreasing order
    int n = heights.size(); // Total number of bars in the histogram

    // Step 1: Iterate through the histogram to calculate areas for each height
    for (int i = 0; i < n; i++) {
        // If the current height is smaller than the height at the index on top of the stack,
        // it means we can't extend the rectangle with the height on top of the stack further.
        while (!st.empty() && heights[st.top()] > heights[i]) {
            index = st.top(); // Get the index of the height to process
            st.pop();         

            // Calculate the area for the height at `index`
            if (!st.empty()) {
                // If the stack is not empty, the width is between the current index `i` 
                // and the new top of the stack (`st.top()`) after popping.
                ans = max(ans, heights[index] * (i - st.top() - 1));
            } else {
                // If the stack is empty, it means the height at `index` is the smallest so far.
                // The width spans from index 0 to the current index `i`.
                ans = max(ans, heights[index] * i);
            }
        }

        // Push the current index onto the stack
        st.push(i);
    }

    // Step 2: Process the remaining elements in the stack
    // If there are still indices in the stack, they represent heights
    // that can extend until the end of the histogram (`n`).
    while (!st.empty()) {
        index = st.top(); // Get the index of the height to process
        st.pop();

        // Calculate the area for the height at `index`
        if (!st.empty()) {
            // If the stack is not empty, the width is between the end of the histogram (`n`)
            // and the new top of the stack (`st.top()`) after popping.
            ans = max(ans, heights[index] * (n - st.top() - 1));
        } else {
            // If the stack is empty, it means the height at `index` is the smallest so far.
            // The width spans the entire histogram (from index 0 to `n`).
            ans = max(ans, heights[index] * n);
        }
    }

    return ans; // Return the largest rectangle area found
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3}; // Input histogram heights

    // Output the largest rectangle area in the histogram
    cout << largestRectangleArea(heights) << endl;

    return 0;
}
