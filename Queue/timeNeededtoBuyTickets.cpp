// Problem Statement :- https://leetcode.com/problems/time-needed-to-buy-tickets/description/

// Let's say you have :- {1, 5, 2, 3, 7} and k = 2 Use a time variable initialized with zero.
// Index 0 only needs 1 ticket, after purchasing that time is increased to one and it is not in queue anymore. Then comes 5, it gets one ticket, time variable is updated to 2, converts to 4 and is pushed at the end. Then comes 2 which reduces to 1, time updates to 3 and it goes at end. Then 3 -> 2, time = 4, push at end. Then 7 -> 6, time = 5
// Now comes 4 (which was 5 previously), it goes 4 -> 3, time = 6. And finally, 1 -> 0, time = 7 and k = 2 needs 7 seconds to get ticket.
// This we will solve using a Queue. In Queue we will put it's index :- {0, 1, 2, 3, 4} 
// Start from 0 index, it is 1 in array, so decrease it by 1, it becomes zero, hence, just dequeue this element's index i.e. 0 from Queue and don't enqueue it back. For rest, if the element doesn't become zero, you have to dequeue and enqueue it into the Queue.
// When the corresponding element for k index becomes 0. We should simply return the value of time variable.

#include <bits/stdc++.h>
using namespace std;

// Function to calculate the time required for person at index 'k' to buy tickets
int timeRequiredToBuy(vector<int>& tickets, int k) {
    queue<int> Q;  // Queue to store the indices of the people in line
    int n = tickets.size();  // Total number of people

    // Initialize the queue with indices of all the people in line
    for (int i = 0; i < n; i++) {
        Q.push(i);  // Push each index (0 to n-1) into the queue
    }

    int time = 0;  // Variable to track the time (number of seconds passed)

    // Continue the loop until the tickets for the person at index `k` are not zero
    while (tickets[k] != 0) {
        // Decrement the ticket count for the person at the front of the queue (Q.front())
        tickets[Q.front()]--;

        // If the person still has more tickets to buy (i.e., ticket count is not zero), re-enqueue the person at the back of the queue
        if (tickets[Q.front()] != 0) {
            Q.push(Q.front());  // Push the person back to the queue
        } 

        // Remove the person at the front from the queue (either they finished or will come back later)
        Q.pop();

        // Increment the time after each transaction
        time++;
    }

    // Return the total time taken when the person at index `k` finishes buying tickets
    return time;
}

int main() {
    vector <int> tickets = {1, 6, 7, 10, 2, 9, 1};
    int k = 2;

    cout << "Time Required to Buy Tickets :- " << timeRequiredToBuy(tickets, k) << endl;

    return 0;
}


// Optimal Approach :- Say you have :- {2, 6, 4, 3, 7} and k = 2
// When k has gotten all 4 tickets that it needs how do we find out how many tickets has other people got?
// For elements/person before k, they will recieve at max 4 tickets and for elements after k, they will receive at max 3 tickets.
// The reason why I said at max is because it can happen that they have less tickets than the maximum. In that case, obv they won't get maximum tickets and will leave the Queue earlier.
// Based on how many tickets everyone has gotten, we can easily find the time required by adding all of them.
// For elements before k, we can say :- time += min(ticket[k], ticket[i]) and for elements after k, we can say :- time += min(ticket[k] - 1, ticket[i]) and for k element :- time += ticket[k]

#include <bits/stdc++.h>
using namespace std;

int timeRequiredToBuy(vector<int>& tickets, int k) {
    int time = 0;  // Variable to store the total time required

    // Loop through each person in the queue (0 to n-1)
    for (int i = 0; i < tickets.size(); i++) {
        if (i <= k) {
            // Case 1: For people before index k (inclusive), they will get at most `tickets[k]` tickets
            // We add the minimum between `tickets[i]` and `tickets[k]` because if they need fewer tickets than tickets[k], 
            // they will leave the queue earlier.
            time += min(tickets[i], tickets[k]);
        } else {
            // Case 2: For people after index k, they can only get `tickets[k] - 1` tickets max
            // This is because by the time we process the kth person fully, they won't need more tickets.
            time += min(tickets[i], tickets[k] - 1);
        }
    }

    // Return the total time calculated
    return time;
}

int main() {
    vector <int> tickets = {1, 6, 7, 10, 2, 9, 1};
    int k = 2;

    cout << "Time Required to Buy Tickets :- " << timeRequiredToBuy(tickets, k) << endl;

    return 0;
}