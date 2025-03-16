// Problem Statement :- https://leetcode.com/problems/lemonade-change/description/

#include <bits/stdc++.h>
using namespace std;

// Function to simulate a lemonade stand where customers pay with $5, $10, or $20 bills.
// Returns true if all customers can be given correct change, false otherwise.
bool lemonadeChange(vector<int>& bills) {
    int five = 0; // Count of $5 bills available as change.
    int ten = 0;  // Count of $10 bills available as change.

    // Iterate through each customer's payment.
    for (int &bill : bills) {
        if (bill == 5) {
            // Customer pays with a $5 bill; no change needed.
            five++;
        } else if (bill == 10) {
            // Customer pays with a $10 bill; needs $5 as change.
            if (five > 0) {
                five--;  // Use one $5 bill for change.
                ten++;   // Add one $10 bill to the available pool.
            } else {
                // Not enough $5 bills to give change.
                return false;
            }
        } else {
            // Customer pays with a $20 bill; needs $15 as change.
            if (five > 0 && ten > 0) {
                // Use one $10 bill and one $5 bill for change.
                five--;
                ten--;
            } else if (five >= 3) {
                // Use three $5 bills for change if no $10 bill is available.
                five -= 3;
            } else {
                // Not enough bills to give $15 as change.
                return false;
            }
        }
    }

    // If all customers were given correct change, return true.
    return true;
}

int main() {
    vector<int> bills1 = {5, 5, 5, 10, 20};
    cout << "Can give change: " << (lemonadeChange(bills1) ? "Yes" : "No") << endl;

    return 0;
}
