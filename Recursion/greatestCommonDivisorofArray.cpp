// Problem Statement :- https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    // Base case: If b becomes 0, a is the GCD
    if (b == 0)
        return a;
    // Recursive call: GCD of b and remainder of a divided by b
    return gcd(b, a % b);
}

int findGCD(vector<int>& nums) {
    // Initialize minElement and maxElement with the first element of the array
    int minElement = nums[0];
    int maxElement = nums[0];

    // Iterate through the array to find the smallest and largest elements
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < minElement) {
            minElement = nums[i]; // Update minElement if current element is smaller
        }
        if (nums[i] > maxElement) {
            maxElement = nums[i]; // Update maxElement if current element is larger
        }
    }

    // Calculate and return the GCD of the smallest and largest numbers
    return gcd(minElement, maxElement);
}

int main() {
    vector<int> nums = {2, 5, 6, 9, 10}; // Example input
    // Call the function to find the GCD of the smallest and largest numbers in the array
    int result = findGCD(nums);

    // Output the result
    cout << "The GCD of the smallest and largest numbers in the array is: " << result << endl;

    return 0;
}
