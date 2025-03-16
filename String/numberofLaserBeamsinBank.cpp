// Problem Statement :- https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

// For first row, obv there will be zero laser beams as no security device is above them. Now before moving to next row, we can maintain a variable prev to count the number of security devices in that row, let's call it prev.
// We will also maintain a variable called curr, to maintain the number of security devices in the current row. If there are no security devices in the current row, there can't be a laser. But for this case, we won't set prev to 0 (let prev be what it was) before moving to next row. As in this case, we know that in this case, laser beam can travel from the row before as the current row has no security devices. 
// When we do have some security devices in the current row, then we can find total number of laser beams as prev * curr for these two rows.
// Ofc, when you move to the next row, don't forget to update prev and curr. 

// Problem Statement :- https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank) {
    int n = bank.size(); // Get the number of rows in the bank
    int prevDeviceCount = 0; // To keep track of the number of security devices in the last non-empty row
    int result = 0; // This will store the total count of laser beams

    // Iterate over each row in the bank
    for (int i = 0; i < n; i++) {
        int currDeviceCount = 0; // Count of security devices in the current row

        // Count the number of '1's (security devices) in the current row
        for (char &ch : bank[i]) {
            if (ch == '1') {
                currDeviceCount++;
            }
        }

        // Calculate beams only if there were devices in the current row
        result += (prevDeviceCount * currDeviceCount); // Beams = devices in previous row * devices in current row

        // Update `prevDeviceCount` to `currDeviceCount` if current row has devices
        // If `currDeviceCount` is 0, we retain the previous row's device count to allow beams to form in future rows
        prevDeviceCount = (currDeviceCount == 0) ? prevDeviceCount : currDeviceCount;
    }

    return result; // Return the total number of beams
}

int main() {
    // Test the function with a sample input
    vector<string> bank = {"011001", "000000", "010100", "001000"};
    cout << "Number of laser beams: " << numberOfBeams(bank) << endl; // Output: 8
}
