// Problem Statement :- https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

// This is Josephus Problem.

// Brute Force Approach :- Take a boolean vector of same size as the number of friends. This will be a circular vector, where you will traverse, and keep increasing the count. When count ebcomes equal to k fora n index, make it's value 1. Next time, when you traverse, don't count those whose value is 1.
// The last index which has 0 remaining as value will be the winner of the game. For this, we can maintain a personLeft variable, which we initialize with size of vector, as we make the elements 1, we also decrease that varaible by 1. When personLeft = 0, simmply traverse the array to find the index which still holds the value 0.
// Obv if k is 4, we will have to move 3 times i.e. k - 1 times (this is because we are also counting the index we are on).
// It could happen that the value of k is greater than the value of n. In that case, we have to move (k - 1) % personLeft (personLeft and not n because if there are 1's we don't have to count them)

// Snce in the problem statement, the friends numbering is starting from 1 isntead of 0. We will return the final answer with 1 added to it.

#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the winner in the circular elimination game.
int winner(vector<bool> &person, int n, int index, int person_left, int k) {
    // Base case: if only one person remains, return the index of the winner.
    if (person_left == 1) {
        for (int i = 0; i < n; i++) {
            if (person[i] == 0) {  // Find the last unmarked person.
                return i;
            }
        }
    }

    // Calculate the number of steps (kills) to the next elimination.
    int kill = (k - 1) % person_left;

    // Move forward by 'kill' steps, skipping already eliminated people.
    while (kill--) {
        index = (index + 1) % n;  // Move to the next position in a circular manner.

        // Skip any eliminated person (marked as 1).
        while (person[index] == 1) {
            index = (index + 1) % n;
        }
    }

    // Mark the current person at 'index' as eliminated.
    person[index] = 1;

    // Move to the next available person for the next elimination round.
    while (person[index] == 1) {
        index = (index + 1) % n;
    }

    // Recursive call to continue the elimination with one less person.
    return winner(person, n, index, person_left - 1, k);
}

// Main function to set up and execute the winner determination.
int findTheWinner(int n, int k) {
    // Initialize a boolean vector to track eliminations (0 = alive, 1 = eliminated).
    vector <bool> person(n, 0);

    // Call the recursive winner function starting with the 0th person, 
    // and return the final winner (index + 1 for 1-based numbering).
    return winner(person, n, 0, n, k) + 1;
}

int main() {
    int n = 10; // Number of players
    int k = 3;  // Step count for each elimination

    // Output the winner of the game.
    cout << "The winner of the game is :- "  << findTheWinner(n, k);
}


// Optimal Approach :- Let's say we had n = 5 and k = 3, friends starting from 0. Then first, 2 will be eliminated. 0, 1, 3, 5 are left. But now, instead of using this, we say that 0, 1, 2, 3 are left. Now there is a pettern that both are starting from 0. And we have even decreased n by 1. 
// But now we want to make some relationshsip, as we are having 0, 1, 2, 3 (starting from 0) left even though it should be 0, 1, 3, 4 (starting from 3). So, we can say that 0 is equivalent to 3, 1 to 4, 2 to 0, and 3 to 1. Everything is same, aside from the numbers. So, for eg :- if 0, 1, 2, 3 gives us 2 as the winner, we should know that 0 is the actual winner.
// And if you observe carefully, we can get 3 from 0, 4 from 1, 0 from 2, and 1 from 3 by adding k (but also take the final result's i.e. (result + k) mod with n i.e. (result + k) % n, this is for cases when (result + k) will become bigger than n as in this case that element won't exist)

#include <bits/stdc++.h>
using namespace std;

// Recursive function to determine the winner of the circular elimination game.
int winner(int n, int k) {
    // Base case: If there is only one person, they are the winner, so return index 0.
    if (n == 1) {
        return 0;
    }

    // Recursive case: Reduce the problem by considering n-1 people, 
    // then find the winner with an adjusted index using modular arithmetic.
    // This formula `(winner(n - 1, k) + k) % n` shifts the winner position of
    // the smaller group by k steps to account for the eliminated person.
    return (winner(n - 1, k) + k) % n;
}

// Wrapper function to call the recursive solution and adjust for 1-based indexing.
int findTheWinner(int n, int k) {
    // Adding 1 to convert the 0-based winner index from the recursive function
    // to a 1-based result as per the problem requirements.
    return winner(n, k) + 1;
}

int main() {
    int n = 10; // Number of players
    int k = 3;  // Step count for each elimination

    // Output the winner of the game.
    cout << "The winner of the game is :- "  << findTheWinner(n, k);
}