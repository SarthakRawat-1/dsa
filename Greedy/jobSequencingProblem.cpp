// Problem Statement :- https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// Deadline of a job represents the latest time (or slot) by which the job must be completed to earn its associated profit.
// We will use an answer array to keep track of deadline and the jobs that are completed. This time slot array will keep track of the free time slots. 
// We will first do the job with maximum profit, but let's say we have deadline for that job as 2 and for second highest profit job as 1, we can't assign the highest profitable job to 1 in our answer deadlock array, as then the job which has 1 as deadline will not be commpleted. 
// We will assign it to 2, and that 1 as deadline to 1.

// Sort by Profit - Start with the job that offers the maximum profit because maximizing profit is the objective.
// Respect Deadlines - When assigning a job to a slot, ensure that :-
// 1. The latest available slot before or equal to its deadline is chosen.
// 2. This prevents blocking earlier deadlines required by other jobs.
// Avoid Conflicts - Jobs with earlier deadlines must have priority for earlier slots to avoid deadlock situations, ensuring feasibility for all jobs.

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Structure to represent a job
// struct Job {
//     int id;       // Job ID
//     int deadline; // Deadline of job
//     int profit;   // Profit for the job
// };

// // Comparator function to sort jobs by profit in descending order
// bool compare(Job a, Job b) {
//     return a.profit > b.profit;
// }

// // Function to find the maximum profit job sequence
// void jobSequencing(vector<Job>& jobs) {
//     // Step 1: Sort all jobs by decreasing order of profit
//     sort(jobs.begin(), jobs.end(), compare);

//     // Step 2: Find the maximum deadline to determine size of slot array
//     int maxDeadline = 0;
//     for (const auto& job : jobs) {
//         maxDeadline = max(maxDeadline, job.deadline);
//     }

//     // Step 3: Create a slot array to track assigned jobs (-1 indicates empty slot)
//     vector<int> slot(maxDeadline + 1, -1); // Slots are indexed from 1 to maxDeadline

//     // Variables to store total profit and count of jobs completed
//     int totalProfit = 0;
//     int jobCount = 0;

//     // Step 4: Place each job in the latest available slot before its deadline
//     for (const auto& job : jobs) {
//         // Check slots from job.deadline down to 1
//         for (int j = job.deadline; j > 0; --j) {
//             // If slot is empty, assign the job here
//             if (slot[j] == -1) {
//                 slot[j] = job.id; // Store job ID in the slot
//                 totalProfit += job.profit; // Add profit
//                 jobCount++; // Increment count of completed jobs
//                 break; // Move to the next job
//             }
//         }
//     }

//     // Step 5: Print the results
//     cout << "Job Sequence: ";
//     for (int i = 1; i <= maxDeadline; ++i) {
//         if (slot[i] != -1) {
//             cout << slot[i] << " ";
//         }
//     }
//     cout << endl;
//     cout << "Total Profit: " << totalProfit << endl;
//     cout << "Number of Jobs Completed: " << jobCount << endl;
// }

// int main() {
//     // Input: List of Jobs (id, deadline, profit)
//     vector<Job> jobs = {{1, 2, 100}, {2, 1, 50}, {3, 2, 20}, {4, 1, 10}, {5, 3, 200}};

//     // Call job sequencing function
//     jobSequencing(jobs);

//     return 0;
// }

// Optimized Solution using Disjoint Set Union (DSU)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a job
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit for the job
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Find function for Disjoint Set Union (DSU)
int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]); // Path compression
}

// Union function for DSU
void unionSet(vector<int>& parent, int u, int v) {
    parent[find(parent, u)] = find(parent, v);
}

// Function to find the maximum profit job sequence using DSU
void jobSequencing(vector<Job>& jobs) {
    // Step 1: Sort all jobs by decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline to create parent array
    int maxDeadline = 0;
    for (const auto& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Step 3: Initialize parent array for DSU
    vector<int> parent(maxDeadline + 1);
    for (int i = 0; i <= maxDeadline; ++i) {
        parent[i] = i; // Each slot points to itself initially
    }

    // Variables to store total profit and count of jobs completed
    int totalProfit = 0;
    int jobCount = 0;

    // Step 4: Process each job
    for (const auto& job : jobs) {
        // Find the latest available slot using DSU
        int availableSlot = find(parent, job.deadline);
        if (availableSlot > 0) { // If a valid slot exists
            // Assign the job to this slot and union sets
            unionSet(parent, availableSlot, availableSlot - 1);
            totalProfit += job.profit;
            jobCount++;
        }
    }

    // Step 5: Print the results
    cout << "Total Profit: " << totalProfit << endl;
    cout << "Number of Jobs Completed: " << jobCount << endl;
}

int main() {
    // Input: List of Jobs (id, deadline, profit)
    vector<Job> jobs = {{1, 2, 100}, {2, 1, 50}, {3, 2, 20}, {4, 1, 10}, {5, 3, 200}};

    // Call job sequencing function
    jobSequencing(jobs);

    return 0;
}

