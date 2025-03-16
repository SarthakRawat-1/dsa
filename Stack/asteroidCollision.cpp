// Problem Statement :- https://leetcode.com/problems/asteroid-collision/description/

// For two asteroids, they can only collide if the first one is positive and the second one (after the first one) is negative.
// To find which asteroid will remain after collision, just take sum of both. The sign of result will tell the sign of asteroid which will remain. If ther result becomes 0, both will be destroyed.

// We are directly implementing stack here with a vector. Could have also taken a Stack but then we would need a vector to store the resultant elements to return them anyway.

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    // Vector 'ans' is used as a stack to keep track of the remaining asteroids after collisions
    vector<int> ans;

    // Iterate through each asteroid in the input 'asteroids' vector
    for (int &a : asteroids) {
        // While loop checks if there is a potential collision scenario:
        // 1. The stack 'ans' is not empty.
        // 2. Current asteroid 'a' is negative (moving left).
        // 3. The top asteroid in the stack 'ans.back()' is positive (moving right).
        // These conditions indicate a possible collision.
        while (!ans.empty() && a < 0 && ans.back() > 0) {
            // Calculate the sum of the current asteroid 'a' and the asteroid on top of the stack
            int sum = a + ans.back();

            // Case 1: If the sum is negative, the current asteroid 'a' is larger in magnitude
            //         than the top of the stack (positive asteroid).
            //         The positive asteroid is destroyed, so we pop it from the stack.
            if (sum < 0) {
                ans.pop_back();
            } 
            // Case 2: If the sum is positive, the top of the stack (positive asteroid) is
            //         larger in magnitude, and the current negative asteroid is destroyed.
            //         Set 'a' to 0 to indicate that the current asteroid has been destroyed.
            else if (sum > 0) {
                a = 0;
            } 
            // Case 3: If the sum is zero, both asteroids are of the same magnitude.
            //         They destroy each other, so pop the top of the stack and set 'a' to 0.
            else {
                ans.pop_back();
                a = 0;
            }
        }

        // After handling collisions, if the current asteroid 'a' is still non-zero (not destroyed),
        // push it onto the stack, meaning it survived the collision or no collision occurred.
        if (a != 0) {
            ans.push_back(a);
        }
    }

    // Return the remaining asteroids after all collisions have been processed.
    return ans;
}

int main() {
    vector<int> asteroids = {-2, -1, 1, 2};

    vector<int> result = asteroidCollision(asteroids);

    for (int r : result) {
        cout << r << " ";
    }
}
