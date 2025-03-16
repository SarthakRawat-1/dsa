// The prefix sum at any index i of an array is the sum of all the elements from the beginning of the array up to the index i (including).
// The suffix sum at any index i of an array is the sum of all the elements from the index i to the end of the array (including).

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the prefix sum of an array
vector<int> calculatePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);

    // First element of prefix sum is the same as the first element of the array
    prefixSum[0] = arr[0];

    // Calculate prefix sum for each element
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

// Function to calculate the suffix sum of an array
vector<int> calculateSuffixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> suffixSum(n);

    // Last element of suffix sum is the same as the last element of the array
    suffixSum[n - 1] = arr[n - 1];

    // Calculate suffix sum for each element
    for (int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + arr[i];
    }

    return suffixSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};

    vector<int> prefixSum = calculatePrefixSum(arr);
    cout << "Prefix Sum Array: ";
    for (int i = 0; i < prefixSum.size(); i++) {
        cout << prefixSum[i] << " ";
    }
    cout << endl;

    vector<int> suffixSum = calculateSuffixSum(arr);
    cout << "Suffix Sum Array: ";
    for (int i = 0; i < suffixSum.size(); i++) {
        cout << suffixSum[i] << " ";
    }
    cout << endl;

    return 0;
}
