// Problem Statement :- https://leetcode.com/problems/minimum-time-visiting-all-points/description/

// Best is to move diagonally, till you are not aligned in a straight line with the point you are visiting. Once you are aligned, take the remaining steps as straight path, either horizontally or vertically.
// In this way, you can find the shortest distance between two points. In the end, jsut add all the distances.
// Let's say you have two points (x1, y1) and (x2, y2). Then, we can say x2 - x1 = dx and y2 - y1 = dy. So, first we move diagonally, till we cover dx (or dy, basically one of them should become zero). Then the dy (or dx, whichever is still not 0) can be covered by straight steps.
// If you visualize this using a square, you will realize that when we have covered dx first such that it is aligned. Now, making a square, we will see that the distance left to be covered is dy - dx. We will have to take it abs, as the point (x2, y2) can also be below the point (x1, y1). So, shortest distance will be dx + abs(dy - dx).
// If we were able to cover dy first such that it is aligned, shortest distance will be dy + abs(dx - dy).
// Generalizing :- min(dx, dy) + abs(dx - dy)
// How do we know if we will cover dx first or dy? Whichever is shorter, we will cover that first using diagonal movements. 

#include <bits/stdc++.h>
using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int n = points.size();  // Get the number of points in the input vector.

    int steps = 0;  // Initialize a variable to count the total steps (or time) needed.

    // Iterate over each pair of consecutive points (points[i] and points[i+1])
    for (int i = 0; i < n - 1; i++) {
        int x1 = points[i][0];     // x-coordinate of the current point
        int y1 = points[i][1];     // y-coordinate of the current point
        int x2 = points[i + 1][0]; // x-coordinate of the next point
        int y2 = points[i + 1][1]; // y-coordinate of the next point

        // Calculate the absolute differences between the x-coordinates (dx) and y-coordinates (dy)
        // dx represents the horizontal distance between the two points
        // dy represents the vertical distance between the two points
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);

        // To minimize time (steps), the best approach is to move diagonally first, covering both dx and dy simultaneously.
        // - We can move diagonally min(dx, dy) times, reducing both dx and dy.
        // - After diagonal movement, if dx != dy, there will be some remaining distance (abs(dx - dy)) to cover either horizontally or vertically.
        // The total steps for this movement are the sum of min(dx, dy) + the remaining distance (abs(dx - dy)).
        steps += min(dx, dy) + abs(dx - dy);
    }

    // After processing all consecutive points, return the total number of steps.
    return steps;
}

int main() {
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    cout << minTimeToVisitAllPoints(points) << endl;
    return 0;
}