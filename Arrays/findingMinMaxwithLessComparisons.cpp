#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum and maximum element using fewer comparisons
pair<int, int> findMinMax(vector<int> &arr) {
    int n = arr.size();
    
    // Edge case: If the array is empty, return an invalid pair
    if (n == 0) return {INT_MAX, INT_MIN};

    int min_val, max_val;
    int i = 0; // Start index

    // If the array size is odd, initialize min and max as the first element
    if (n % 2 == 1) {
        min_val = max_val = arr[0];
        i = 1; // Start processing from the second element
    } else {
        // If even, initialize min and max using the first two elements
        if (arr[0] < arr[1]) {
            min_val = arr[0];
            max_val = arr[1];
        } else {
            min_val = arr[1];
            max_val = arr[0];
        }
        i = 2; // Start processing from the third element
    }

    // Process pairs of elements
    while (i < n - 1) {
        int local_min, local_max;
        
        // Compare two elements to determine local min and max
        if (arr[i] < arr[i + 1]) {
            local_min = arr[i];
            local_max = arr[i + 1];
        } else {
            local_min = arr[i + 1];
            local_max = arr[i];
        }

        // Update global min and max
        if (local_min < min_val) min_val = local_min;
        if (local_max > max_val) max_val = local_max;

        i += 2; // Move to the next pair
    }

    return {min_val, max_val};
}

int main() {
    vector<int> arr = {3, 1, 5, 9, 8, 2, 7};

    pair<int, int> result = findMinMax(arr);
    cout << "Minimum: " << result.first << endl;
    cout << "Maximum: " << result.second << endl;

    return 0;
}
