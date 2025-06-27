// Problem Staement :- https://leetcode.com/problems/boats-to-save-people/description/

// We will first sort the people array in ascending order. This way, we can pair the lightest person with the heaviest person.
// Hence, we will need two pointers, i and j, to track the lightest and heaviest person respectively.

#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    // Get the number of people
    int n = people.size();
    
    // Sort the array in ascending order to facilitate pairing the lightest and heaviest individuals
    sort(begin(people), end(people));

    // Initialize two pointers:
    // 'i' starts at the lightest person (beginning of array)
    // 'j' starts at the heaviest person (end of array)
    int i = 0, j = n - 1;

    // Counter to track the number of boats needed
    int boats = 0;

    // Process pairs until all people are accounted for
    while (i <= j) {
        // Check if the lightest and heaviest person can share a boat
        if (people[j] + people[i] <= limit) {
            // If they can, move both pointers inward: lightest (i++) and heaviest (j--)
            i++;
            j--;
        } else {
            // If they can't share a boat, the heaviest person (j) must go alone
            j--;
        }
        // Increment the boat count for each iteration, whether paired or solo
        boats += 1;
    }

    // Return the total number of boats required
    return boats;
}

int main() {
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    cout << numRescueBoats(people, limit) << endl;
    return 0;
}