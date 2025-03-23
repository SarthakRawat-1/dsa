// Problem Statement :- 

#include <bits/stdc++.h>
using namespace std;

// Using Unordered Map :- Count frequencies of all elements. If any element has odd frequency, return false. Otherwise, return true.
bool divideArray(vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    for (auto& p : freq) {
        if (p.second % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Using Frequency Array :- Since the values are in the range [1, 500], you can use a fixed-size vector (or array) of size 501 instead of an unordered map. This avoids hashing overhead and is typically faster in practice, while still running in O(n) time.
// bool divideArray(vector<int>& nums) {
//     vector<int> freq(501, 0);
//     for (int num : nums) {
//         freq[num]++;
//     }
//     for (int count : freq) {
//         if (count % 2 != 0) {
//             return false;
//         }
//     }
//     return true;
// }

// // Using Sorting :- Another alternative is to sort the array and then check if each adjacent pair consists of the same element.
// bool divideArray(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     for (size_t i = 0; i < nums.size(); i += 2) {
//         if (nums[i] != nums[i + 1]) {
//             return false;
//         }
//     }
//     return true;
// }

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool result = divideArray(nums);
    cout << "Can the array be divided into pairs? " << (result ? "Yes" : "No") << endl;
    return 0;
}
