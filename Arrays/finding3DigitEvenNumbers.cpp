// Problem Statement :- https://leetcode.com/problems/finding-3-digit-even-numbers/description/

// At hundreth place, we can put digits from 1 to 9, in tenth place, we can also place 0, but on one place, we can only put 0, 2, 4, 6, 8 for it to be an even number.
// We can make for loops, for each of the place where for loop variable will take the values which are allowed at that place.
// But we also have to make sure that the digits we are taking, should be present in array. For this, we can use a map (or array with size 10 as digits range from 0 to 9 which will be index and value represents frequency).

#include <bits/stdc++.h>
using namespace std;


vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> result;

    // Map to count the frequency of each digit (0-9)
    vector<int> map(10, 0);
    for (int &digit : digits) {
        map[digit]++;
    }

    // Try all possible combinations for a 3-digit number
    // First digit (hundreds place) must be 1 to 9 (non-zero)
    for (int i = 1; i <= 9; i++) {
        if (map[i] == 0) continue; // Skip if digit i is not available
        map[i]--; // Use one instance of digit i

        // Second digit (tens place) can be 0 to 9
        for (int j = 0; j <= 9; j++) {
            if (map[j] == 0) continue; // Skip if digit j is not available
            map[j]--; // Use one instance of digit j

            // Third digit (units place) must be even: 0, 2, 4, 6, or 8
            for (int k = 0; k <= 8; k += 2) {
                if (map[k] == 0) continue; // Skip if digit k is not available
                map[k]--; // Use one instance of digit k

                // Form the 3-digit even number and add to result
                int num = i * 100 + j * 10 + k;
                result.push_back(num);

                map[k]++; // Restore digit k
            }
            map[j]++; // Restore digit j
        }
        map[i]++; // Restore digit i
    }

    return result;
}

int main() {
    vector<int> digits = {2, 1, 3, 0};
    vector<int> result = findEvenNumbers(digits);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}