// Problem Statement :- https://leetcode.com/problems/count-days-without-meetings/

// When you have to deal with intervals, always try to sort, and see if that helps.
// In our case, we will sort based on starting time of each interval.
// Consider :- [(1, 3), (5, 7), (9, 10)], take starting time of 2nd meeting 5 and ending time of first meeting 3. There is gap between them. So, start - end - 1 = free hours
// We can be sure that the two meetings that we took will be back to back because we sorted them first.

// Since, meetings can overlap, consider this eg :- [(1, 5), (2, 4)], days = 10
// As 2 < 5, so there will be no days off. But it's ending time is 4. So our answer remained 0, which is not correct.
// Hence, when we have checked all cases, we will check if days > end, and return days - end. But, now end will not change for every meeting.
// end will update as max(prev_meeting, curr_meeting)

#include <bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    int n = meetings.size();

    // Sort meetings by start time to process them in order
    sort(begin(meetings), end(meetings));

    int result = 0; // Variable to store the count of free days
    int start = 0;  // Variable to track the start of the last processed meeting range
    int end = 0;    // Variable to track the end of the last processed meeting range

    // Iterate through each meeting
    for(auto &meet : meetings) {
        // If there's a gap between the previous meeting and the current one, count free days
        if(meet[0] > end) {
            result += meet[0] - end - 1; // Add the gap (exclusive of meeting days)
        }

        // Update the end to the maximum end seen so far
        end = max(end, meet[1]);
    }

    // If there are free days after the last meeting until 'days', count them
    if(days > end) {
        result += days - end;
    }

    return result;
}

int main() {
    int days = 10;
    vector<vector<int>> meetings = {{1, 3}, {5, 7}, {9, 10}};
    int result = countDays(days, meetings);
    cout << "Number of free days: " << result << endl;
    return 0;
}