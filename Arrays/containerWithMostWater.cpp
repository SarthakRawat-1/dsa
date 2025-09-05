// Problem Statement :- https://leetcode.com/problems/container-with-most-water/description/

// Area is width x height.
// Let's say whatever heights we choose, the actual height till where water will fill, will be the smaller height.
// So ofc, if we want to minimize width, we have to make heigh bigger for a bigger area.
// Let's say you have start from those two heights at the opposite end. Calc area. Now you have to move one of the heights (leftmost one to right by one or rightmost one to left by one).
// You should move the smaller of the two, because after moving width is reduced, so we should increase height. Calc area again and store max of area. Keep doing this, till exhaustion.

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int height1 = 0, height2 = height.size() - 1;
    int maxArea = 0;

    while (height1 < height2) {
        int width = height2 - height1;
        int heightofContainer = min(height[height1], height[height2]);

        maxArea = max(maxArea, width * heightofContainer);

        if (heightofContainer == height[height1]) {
            height1++;
        } else {
            height2--;
        }
    }

    return maxArea;
}

int main() {

}