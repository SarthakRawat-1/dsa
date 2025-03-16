// Problem Statement :- https://leetcode.com/problems/single-threaded-cpu/description/

// We will maintain a timer variable. This timer variable will start from 0 and increase one by one (if we are executing a task, then that task's execution time will directly be added to the timer).
// For each value of timer, we will check how many tasks are ready to be executed. We will pich that task which takes the least time to execute.
// Thisvis however not a good approach to solve this problem.

// For a better appraoch, we will still take a timer variable starting from 0. First we will sort the entries by the time at which tasks are coming to the ready queue and can be executed.
// We will use a pointer, to determine how many processes are available at a certain time. Timer will increase just like before.
// Whenever you get a task which ready time is greater than timer, stop the pointer at that entry.
// It can happen, that after executing a process or even by simply increasing by one normally, timer moves to a value where multiple tasks can now be executed. We need to execute the one with shortest execution time. For this we will use Min Heap.
// In heap, we will only store the task's number and their execution time, no need to store their ready time.
// Also, instead of starting timer with 0, we can start timer with the ready time of first entry (after sorting).
// Similarly, after executing a task, moving pointer to next entry. If we have empty min heap (no processes ready to be executed) and the next entry ready time is greater than time value, we can simply increase timer value to that entry's ready time.

#include <bits/stdc++.h>
using namespace std;

// Function to determine the order of task execution based on the given criteria
vector<int> getOrder(vector<vector<int>>& tasks) {
    vector<int> ans; // To store the order of task execution

    int n = tasks.size(); // Number of tasks

    // Append the original index of each task to preserve the order in the result
    for (int i = 0; i < n; i++) {
        tasks[i].push_back(i);
    }

    // Sort tasks based on their ready time (tasks[i][0])
    sort(tasks.begin(), tasks.end());

    // Initialize the timer with the ready time of the first task
    long long timer = tasks[0][0];

    // Pointer to traverse through the tasks
    int i = 0;

    // Min-heap to prioritize tasks based on shortest processing time
    // Each entry in the heap is a pair {processing time, index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Continue processing tasks until all tasks are handled
    while (i < n || !pq.empty()) {
        // Add all tasks that are ready at the current timer to the priority queue
        while (i < n && timer >= tasks[i][0]) {
            pq.push({tasks[i][1], tasks[i][2]}); // {processing time, index}
            i++;
        }

        // If no tasks are available to process, jump to the next available task's ready time
        if (pq.empty()) {
            timer = tasks[i][0];
        } else {
            // Process the task with the shortest processing time
            ans.push_back(pq.top().second); // Store the task index in the result
            timer += pq.top().first;       // Increase the timer by the task's processing time
            pq.pop();                      // Remove the processed task from the queue
        }
    }

    return ans; // Return the execution order of tasks
}

int main() {
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};

    vector<int> order = getOrder(tasks);

    cout << "Task execution order: ";
    for (int task : order) {
        cout << task << " ";
    }
    cout << endl;

    return 0;
}
