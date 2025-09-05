// Problem Statement :- https://leetcode.com/problems/trapping-rain-water/description/

// Let's assume we have buildings represnted by the array :- {4, 2, 0, 5, 2, 6, 2, 3}
// Initially, we assume water to fall on 4. But there's nothing on it's left and a building with shorter height on it's right, so water can't be stored on 4. If water falls on 2 (at index 1), then 2 units of water can be stored as on it's left, there is a building of 4. On it's right, there's nothing, but on the right of that, there's a building of unit 5, which can support that water.
// Next we move on to 0, here we can have a water of unit 4. Because on it's left there is a building of 2, but on 2's left, there is a building of 4, so it can support that. Also, there is a building of 5 on right, which can support this. If we increase water furthermore, then it'll trickle down from 4 building to outside.
// Now coming to building 5, there can't be any water stored as it'll trickle down from 4. Again, for the 2 at index 4, water can be stored for 3 units. For 6, no water can be stored.
// For 2 at index 6, only one unit of water can be stored. And no unit of water can be stored at 3.
// Hence, our answer :- {0, 2, 4, 0, 3, 0, 1, 0} i.e. total 10 units of water can be stored. 
// Basically for any building, we are trying to find the maximum length of building on both sides then the minimum of these two maximum, till there we can store water over that building, as water needs support from both sides to hold. If we take the biggest of the two, the water will trickle down from the shorter of the two. If the smaller of the two, is less than the height of building, then no water can be stored.
// For eg :- Take 0 again, on the left side, max length is 4 and on the right side it is 6. So water can be stored for 4 - 0 units. If we try to fill till 6 units, the rest two units will flow outside via the 4 building.
// To calculate, consider the area before the first building and after the last building to be buildings with height 0 (as they don't exist).

// We can create two arrays, with same size as that of buildings. One for storing maximum length building on left for each element. Another for storing maximum length building on right for each element.

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    // Get the size of the height array (number of buildings)
    int n = height.size();

    // Edge case: If there are no buildings, no water can be trapped
    if (n == 0) return 0;

    // Create two vectors to store the maximum height of buildings to the left and right of each building
    vector<int> leftmax(n), rightmax(n);

    // Initialize the leftmax array
    // For the first building, there's no building on its left, so leftmax[0] is 0
    leftmax[0] = 0;

    // Initialize the rightmax array
    // For the last building, there's no building on its right, so rightmax[n - 1] is 0
    rightmax[n - 1] = 0;

    // Fill the leftmax array
    // Traverse from the second building (index 1) to the last building (index n-1)
    for (int i = 1; i < n; i++) {
        // For each building at index i, store the maximum height of the buildings to its left
        // leftmax[i] will be the maximum of leftmax[i-1] (max height of buildings to the left of i-1)
        // and height[i-1] (height of the building just to the left of the current building)
        leftmax[i] = max(leftmax[i - 1], height[i - 1]);
    }

    // Fill the rightmax array
    // Traverse from the second-to-last building (index n-2) to the first building (index 0)
    for (int i = n - 2; i >= 0; i--) {
        // For each building at index i, store the maximum height of the buildings to its right
        // rightmax[i] will be the maximum of rightmax[i+1] (max height of buildings to the right of i+1)
        // and height[i+1] (height of the building just to the right of the current building)
        rightmax[i] = max(rightmax[i + 1], height[i + 1]);
    }

    // Variable to accumulate the total amount of water trapped
    int water = 0;

    // Calculate the amount of water trapped on each building
    for (int i = 0; i < n; i++) {
        // For each building at index i, the amount of water that can be trapped above it
        // is determined by the minimum height of the tallest buildings to its left and right.
        int minheight = min(leftmax[i], rightmax[i]);

        // Water can only be trapped if the minimum height of buildings around this building
        // is greater than the height of the building itself (otherwise, no water can be held)
        if (minheight > height[i]) {
            // Add the difference between the minimum of leftmax and rightmax, and the building's height
            // This difference gives the amount of water trapped above the current building
            water += minheight - height[i];
        }
    }

    // Return the total amount of water trapped
    return water;
}

int main() {
    vector <int> height = {4, 2, 0, 5, 2, 6, 2, 3};

    int water = trap(height);

    cout << "Trapped water units :- " << water << endl;
}


// We can optimize this code further to improve space complexity. We can do this question without using any extra space.
// We can easily find the maximum height leftmost building, as we are traversing the array, but how do we find the maximum height rightmost building?
// We can use a trick, as we know that ultimately, we want max(maxleft, maxright), we will do something such that we only get maxleft as the output. This will happen when maxright is greater than maxleft.
// For this, first before doing anything, find the maximum length building in the entire array and it's index. Using this, we can easily find the answer for every building to the left of maximum height building. For them, we can use leftmax and water variables both intialized with zero. leftmax variable will be used to hold the maximum left building, which will get updated (when needed) on traversal of array. Ofc for these elements, we don't care about right max because it is the largest building in the entire array. And obviously, we want minimum of the two.
// For elements on the right of the maximum length building, they don't have to care about left max. They have to only care about right max, so for this also, make a variable maxright initialized with 0. Now for these buildings, start from the rightmost end and go left till you encounter the maximum height building.

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    if (n == 0) return 0;  // Edge case: If there are no buildings, return 0.

    // Step 1: Find the index of the maximum height building in the array.
    int maxIndex = max_element(height.begin(), height.end()) - height.begin();

    // Variables to track the maximum height of buildings seen so far.
    int leftmax = 0;  // This keeps track of the maximum building height from the left side.
    int rightmax = 0;  // This keeps track of the maximum building height from the right side.

    int water = 0;  // Variable to store the total amount of trapped water.

    // Step 2: Traverse the left side from index 0 to maxIndex.
    // In this loop, we only care about the buildings on the left of the tallest building.
    for (int i = 0; i < maxIndex; i++) {
        // Update leftmax as the maximum of current leftmax and the current building's height.
        leftmax = max(leftmax, height[i]);

        // Water can be trapped if leftmax is greater than the current building's height.
        // The trapped water above the current building is (leftmax - height[i]).
        water += max(0, leftmax - height[i]);  // Ensure no negative water values.
    }

    // Step 3: Traverse the right side from index n-1 to maxIndex.
    // In this loop, we only care about the buildings on the right of the tallest building.
    for (int i = n - 1; i > maxIndex; i--) {
        // Update rightmax as the maximum of current rightmax and the current building's height.
        rightmax = max(rightmax, height[i]);

        // Water can be trapped if rightmax is greater than the current building's height.
        // The trapped water above the current building is (rightmax - height[i]).
        water += max(0, rightmax - height[i]);  // Ensure no negative water values.
    }

    // Return the total trapped water.
    return water;
}

int main() {
    vector <int> height = {4, 2, 0, 5, 2, 6, 2, 3};

    int water = trap(height);

    cout << "Trapped water units :- " << water << endl;
}


// In previous method, we were using two traversal, what if we wanted to do it in a single traverse?
// When we know that answer can be obtained by two or more traversals, and we want to do it in a single one, we can use Two Pointer approach.
// Take two pointers, one at the beginning (left) and one at the end (right) of the array. We also track the maximum height seen so far from the left (leftmax) and from the right (rightmax). The trick is to process the shorter side first because the amount of water trapped depends on the shorter boundary.

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;  // Edge case: If there are no buildings, return 0.

    // Two pointers starting from both ends of the array.
    int left = 0;        // Points to the first building.
    int right = n - 1;   // Points to the last building.

    // Variables to store the maximum heights encountered so far from the left and right sides.
    int leftmax = 0;     // Max height encountered from the left.
    int rightmax = 0;    // Max height encountered from the right.

    int water = 0;       // Total amount of trapped water.

    // Traverse the array until the two pointers meet.
    while (left <= right) {
        // We process the shorter side first.
        if (height[left] <= height[right]) {
            // If the current building at 'left' is shorter than the building at 'right'.
            
            if (height[left] >= leftmax) {
                // If the current building is taller than or equal to the maximum height seen from the left,
                // update the leftmax to the height of this building.
                leftmax = height[left];
            } else {
                // If the current building is shorter than leftmax, water can be trapped.
                // The water trapped is (leftmax - height[left]).
                water += leftmax - height[left];
            }
            
            // Move the left pointer to the right, to check the next building.
            left++;
        } else {
            // If the building at 'right' is shorter than the building at 'left'.

            if (height[right] >= rightmax) {
                // If the current building is taller than or equal to the maximum height seen from the right,
                // update the rightmax to the height of this building.
                rightmax = height[right];
            } else {
                // If the current building is shorter than rightmax, water can be trapped.
                // The water trapped is (rightmax - height[right]).
                water += rightmax - height[right];
            }

            // Move the right pointer to the left, to check the next building.
            right--;
        }
    }

    return water;  // Return the total trapped water.
}

// Stack Approach
int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;              // Total trapped water
    stack<int> st;              // Stack to store indices of bars (monotonic decreasing stack)

    // Traverse all bars one by one
    for (int i = 0; i < n; i++) {

        // While current bar is taller than the bar at top of stack
        // → means we found a "right boundary" to trap water
        while (!st.empty() && height[i] > height[st.top()]) {

            int bottom = st.top();   // The "valley" index (potential water bottom)
            st.pop();                // Remove it to calculate water

            if (st.empty()) break;   // No left boundary → cannot trap water

            int left = st.top();     // New left boundary index after popping
            int distance = i - left - 1;  // Width between left and current bar
            int boundedHeight = min(height[i], height[left]) - height[bottom];
            // Water height = bounded by shorter of (current bar, left bar)
            // minus the height of the valley (bottom)

            water += distance * boundedHeight;  // Add trapped water
        }

        // Push current bar index to stack
        // It might be a future "left boundary" for trapping water
        st.push(i);
    }

    return water;  // Return total trapped water
}

int main() {
    vector <int> height = {4, 2, 0, 5, 2, 6, 2, 3};

    int water = trap(height);

    cout << "Trapped water units :- " << water << endl;
}