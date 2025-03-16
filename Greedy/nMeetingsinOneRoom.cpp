// Problem Statement :- https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// Let's say we have Start = {1, 3, 0, 5, 8, 5} and End = {2, 4, 6, 7, 9, 9}
// Let's allocate room to meeting that starts the earliest, in our case 0, which ends at 6. After this, we only have one meeting which can be started, 8. So in this case, we only have 2 meetings hosted.
// Instead of this, allocate the room to meeting that ends the earliest, in our case it is 1 to 2. After this, meeting ending at 4 ends the earliest and it's starting time 3, is more than ending time of previous meeting. So we allocate room to this.
// After this, meeting ending at 6 ends the earliest but it's starting time 0, is less than ending time of previous meeting. So we can't allocate room to this.
// After this, we have 5 to 7 which can also not be allocated. Finally 8 to 9 can be allocated in the room. And in total we got 4 meetings.

// First we will sort End (ofcourse the corresponding Start must also move with them).

#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort meetings based on their ending times
// This helps to select the meeting that finishes the earliest.
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

// Function to calculate the maximum number of meetings that can be held in a single room
int maxMeetings(int start[], int end[], int n) {
    // Create a vector of pairs where each pair represents a meeting's start and end times.
    // We will sort this vector based on the end times.
    vector<pair<int, int>> timer;

    // Filling the vector with start and end times from the arrays.
    for (int i = 0; i < n; i++) {
        timer.push_back({start[i], end[i]});
    }

    // Sort the meetings based on their end time.
    // The meeting that finishes the earliest will come first.
    sort(timer.begin(), timer.end(), compare);

    int total = 0;    // To keep track of the number of meetings that can be held
    int ending = -1;  // Variable to track the end time of the last meeting we allocated the room to.

    // Iterate over the sorted meetings.
    for (int i = 0; i < n; i++) {
        // If the start time of the current meeting is greater than the end time of the last selected meeting,
        // we can allocate the room to this meeting.
        if (timer[i].first > ending) {
            total++;       // Increment the count of meetings.
            ending = timer[i].second;  // Update the last end time to the current meeting's end time.
        }
    }

    return total;  // Return the total number of meetings that can be held.
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5}; 
    int end[] = {2, 4, 6, 7, 9, 9}; 
    int n = sizeof(start) / sizeof(start[0]); 
    cout << maxMeetings(start, end, n); 
    return 0;
}