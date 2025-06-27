#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Job Sequencing with Deadlines - Greedy Approach

// Problem Introduction:
- We are given a set of jobs.
- Each job has:
    * A deadline: the time before which it must be completed.
    * A profit: the reward for completing the job within its deadline.
- Each job takes exactly 1 unit of time to complete.
- We must schedule the jobs to maximize the total profit.

Assumptions:
- Only one job can be processed at a time.
- A machine (e.g., typist) processes the jobs, and each takes 1 hour.

Why Greedy?
- This is a maximization problem with constraints.
- Greedy method is suitable as we make locally optimal choices (i.e., pick the job with highest profit first).

Greedy Strategy:
1. Sort all jobs in descending order of profit.
2. Iterate through each job and try to assign it to the latest possible available slot before its deadline.
3. If a slot is available, assign the job.
4. Continue this until no more jobs can be scheduled.

Time Slots:
- Determine the maximum deadline among all jobs.
- Create an array of time slots up to that maximum.
- Each slot represents 1 unit of time (e.g., 1 hour).
*/

typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

// Comparator function to sort jobs in descending order of profit
int compareJobs(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

// Function to schedule jobs to maximize profit
void jobScheduling(Job jobs[], int n) {
    // Step 1: Sort jobs by descending profit
    qsort(jobs, n, sizeof(Job), compareJobs);

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Step 3: Create time slots array and initialize as free
    int slots[maxDeadline];
    char scheduledJobs[maxDeadline][5];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = 0; // 0 means slot is free
    }

    int totalProfit = 0;
    int count = 0;

    // Step 4: Assign jobs to slots
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                slots[j] = 1;
                strcpy(scheduledJobs[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    // Output the result
    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i]) {
            printf("%s ", scheduledJobs[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

// Example usage
int main() {
    /*
    Example Jobs:
    Job    Deadline    Profit
    J1        2           20
    J2        2           15
    J3        1           10
    J4        3            5
    J5        3            1
    */

    Job jobs[] = {
        {"J1", 2, 20},
        {"J2", 2, 15},
        {"J3", 1, 10},
        {"J4", 3, 5},
        {"J5", 3, 1}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);
    return 0;
}


// Simplified Code
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

// Comparator to sort jobs by descending profit
int compare(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobScheduling(Job jobs[], int n) {
    // Sort jobs by profit
    qsort(jobs, n, sizeof(Job), compare);

    // Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    // -1 means free slot
    int scheduled[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        scheduled[i] = -1;

    int totalProfit = 0;

    // Try to place each job in latest available slot
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (scheduled[j] == -1) {
                scheduled[j] = i;  // store index of job
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print scheduled jobs
    printf("Scheduled Jobs: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (scheduled[i] != -1)
            printf("%s ", jobs[scheduled[i]].id);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    Job jobs[] = {
        {"J1", 2, 20},
        {"J2", 2, 15},
        {"J3", 1, 10},
        {"J4", 3, 5},
        {"J5", 3, 1}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    jobScheduling(jobs, n);
    return 0;
}
