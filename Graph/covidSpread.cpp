// Problem Statement :- https://www.geeksforgeeks.org/problems/covid-spread--141631/1

// The Covid in this question is behaving like a node in BFS.
// If at any unit of time, there are no more additional covid patients, then we will have to subtract this time unit as we haev to find minimum time unit.

// Use BFS
// Initially, add all the 2's in a queue (i.e. their position in the 2D matrix). Then, we pop one element from the queue. It will make adjacent 1's to 2's. Similarly goes for the other 2's. The new 2's will be added to queue ofc. Add the new 2's as soon as they are created by processing for an individual 2's.
// We haev to be careful to maintain a timer, which keeps the time units passed. We also have to make sure to correctly track which 2's are part of which timer.
// When queue becomes empty, we have processed every possibility. If there's still 1 left somewhere in graph, the answer is impossible.
// Keep in mind, if at any timer, no new patients are created, we have to reduce that time from timer.

#include <bits/stdc++.h>
using namespace std;

// Global variables for number of rows and columns in the hospital grid
int r;
int c;

// Helper function to check if a cell (i, j) lies within grid boundaries
bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int helpatrep(vector<vector<int>> hospital) {
    r = hospital.size();         // Total rows
    c = hospital[0].size();      // Total columns

    queue<pair<int, int>> q;     // Queue to perform BFS for all initial Covid patients

    // Add all initial Covid-infected positions (value 2) into the queue
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    // The Covid in this question is behaving like a node in BFS.
    // If at any unit of time, there are no more additional covid patients, 
    // then we will have to subtract this time unit as we have to find minimum time unit.

    int timer = 0; // Time counter to track how long it takes for all 1's to become 2's

    while (!q.empty()) {
        timer++; // Increase time as each BFS level takes 1 time unit

        int curr_patient = q.size(); // Number of Covid nodes to process in this time unit
        bool spread = false;         // To check if any new infections happen this round

        while (curr_patient--) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Directions: up, down, left, right
            // Since this is constant, we can make it a global variable, so it is not redeclared again and again.
            int row[4] = {-1, 1, 0, 0};
            int col[4] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];

                // Check if adjacent cell is valid and uninfected (value 1)
                if (valid(ni, nj) && hospital[ni][nj] == 1) {
                    hospital[ni][nj] = 2; // Infect the cell
                    q.push(make_pair(ni, nj)); // Add newly infected to queue
                    spread = true; // At least one infection occurred this round
                }
            }

            // Instead of writing these all separately, we compressed it above.
            // if (hospital[i - 1][j] == 1) {
            // }
            // if (hospital[i + 1][j] == 1) {
            // }
            // if (hospital[i][j - 1] == 1) {
            // }
            // if (hospital[i][j + 1] == 1) {
            // }
        }

        // If no new infections occurred, subtract last incremented time
        if (!spread) timer--;
    }

    // After BFS traversal, if any 1 (uninfected patient) remains, return -1
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 1) {
                return -1; // Not all patients can be infected
            }
        }
    }

    return timer; // Minimum time required to infect all patients
}

int main() {
    // You can add test cases here to check the function
    vector<vector<int>> hospital = {
        {2, 1, 0},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << helpatrep(hospital) << endl; // Expected output depends on the configuration
    return 0;
}
