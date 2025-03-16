// Problem Statement :- https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

// We are given three rods, source, helper and destiantion. 
// The strategy is to move the biggest disk from source rod to destiantion rod. Barring that, the rest of the disks should all come at the helper rod. 
// After this, the next step is to move the second biggest disk on top of biggest disk on destiantion rod. The rest of the disks should now all come at the starter rod again.
// This continues, till we move all the disks to the destination rod.
// Hence, we can say that if we have n disks, then we want to move n - 1 disk to the helper rod, move the biggest disk to destination rod. After this, we can move these n - 1 disk on top of the biggest disk.
// But how do we move n - 1 disk to the helper rod? Consider this as a new problem altogether. So, now we have n - 1 disk which we want to move to helper rod. Hence, first we have to move n - 2 rods to destiantion rod.
// This can be considered a new problem altogether. n - 2 disk to move to destination rod, so n - 3 disk to move to helper rod. 
// Keep doing this till you reach only 1 disk. For a single disk, we can simply move it to that rod.
// When you are moving back up the recursion tree. You will have to break these problems into smaller portions again. 
// Eg :- Consider you had only one rod in the end, you put it on helper rod. Going one step up the recursion tree, we wanted to put 2 rods at destiantion rod. So we put one rod on helper rod, the other rod on destination rod, and finally transfer that one rod from helper rod to destiantion rod.
// Again, going one step up the recursion tree, we wanted to put 3 rods on helper rod. So we put one rod on destination rod, another one on helper rod and finally transfer that one rod from destination to helper. We already know from previous step, how to transfer the top 2 rods to destiantion rod. Then the last rod, we can simply put to helper rod. 
// How do we transfer the remaining two rods from destination rod to helper rod? We can consider this also as a subproblem. For this, we will have to first put one rod to source rod.

// The total moves required to solve the Tower of Hanoi problem with n disks is 2 ^ n − 1
// If there is only 1 disk (n = 1), it takes exactly 1 move to transfer it from the source rod to the destination rod.
// Proof :- https://math.stackexchange.com/questions/302165/basic-proof-by-mathematical-induction-towers-of-hanoi

#include <bits/stdc++.h>
using namespace std;

// Function to perform the recursive steps of the Tower of Hanoi
// n     : the number of disks to be moved
// sour  : the source rod (rod from which disks will be moved initially)
// help  : the helper (auxiliary) rod used temporarily during moves
// dest  : the destination rod (rod to which disks will be moved ultimately)
void tohcal(int n, int sour, int help, int dest) { 
    // Base case: If there's only one disk, simply move it directly from the source rod to the destination rod
    if (n == 1) {
        cout << "Move disk 1 from rod " << sour << " to rod " << dest << endl;
        return;
    }

    // Recursive call to move the top (n-1) disks from source rod to helper rod, using destination as an auxiliary
    tohcal(n - 1, sour, dest, help);

    // Move the nth (largest) disk from the source rod to the destination rod
    cout << "Move disk " << n << " from rod " << sour << " to rod " << dest << endl;

    // Recursive call to move the (n-1) disks from helper rod to destination rod, using source as an auxiliary
    tohcal(n - 1, help, sour, dest);
}

// Main Tower of Hanoi function that calculates and initiates the process
// n     : the total number of disks
// from  : the source rod where disks are initially placed
// to    : the destination rod where disks will be moved
// aux   : the auxiliary (helper) rod used temporarily during the process
long long toh(int n, int from, int to, int aux) {
    // Call tohcal to execute the sequence of moves based on recursive logic
    tohcal(n, from, aux, to);

    // Return the total number of moves, calculated by 2^n - 1
    return pow(2, n) - 1;
}

int main() {
    int n;  
    cout << "Enter the number of disks: ";
    cin >> n;

    int sourceRod = 1;        
    int destinationRod = 3;   
    int helperRod = 2;        

    long long totalMoves = toh(n, sourceRod, destinationRod, helperRod);
    cout << "Total moves required: " << totalMoves << endl;

    return 0;
}


// // Iterative Solution

// #include <bits/stdc++.h>
// using namespace std;

// // Function to implement the iterative solution for Tower of Hanoi
// void towerOfHanoiIterative(int n, int source, int destination, int auxiliary) {
//     // Calculate the total number of moves required, which is 2^n - 1
//     int totalMoves = pow(2, n) - 1;

//     // Create a vector array to represent the three rods (each vector stores disks on that rod)
//     // rods[0] represents the source rod, rods[1] the destination rod, and rods[2] the auxiliary rod
//     vector<int> rods[3] = { {}, {}, {} };

//     // Initialize the source rod with disks in decreasing order (from n to 1)
//     // so that rods[source - 1] has the largest disk at the bottom and smallest at the top
//     for (int i = n; i >= 1; i--) {
//         rods[source - 1].push_back(i);
//     }

//     // Determine the indices of rods based on whether the number of disks (n) is odd or even
//     // This adjustment in rod mapping ensures the correct move order for each disk
//     int s = source - 1;       // Index for source rod
//     int d = destination - 1;  // Index for destination rod
//     int a = auxiliary - 1;    // Index for auxiliary rod
    
//     // If the number of disks (n) is even, we swap the destination and auxiliary rods
//     // This is necessary to ensure correct disk movement patterns for even n values
//     if (n % 2 == 0) {
//         swap(d, a);
//     }

//     // Begin the iterative process to move disks according to the Tower of Hanoi rules
//     for (int i = 1; i <= totalMoves; i++) {
//         if (i % 3 == 1) { 
//             // Case 1: Move between source (s) and destination (d)
//             if (rods[s].empty() || (!rods[d].empty() && rods[s].back() > rods[d].back())) {
//                 // If source rod is empty or top disk on destination is smaller, move disk from d to s
//                 rods[s].push_back(rods[d].back());
//                 cout << "Move disk " << rods[d].back() << " from rod " << d + 1 << " to rod " << s + 1 << endl;
//                 rods[d].pop_back();
//             } else {
//                 // Otherwise, move the top disk from source to destination
//                 rods[d].push_back(rods[s].back());
//                 cout << "Move disk " << rods[s].back() << " from rod " << s + 1 << " to rod " << d + 1 << endl;
//                 rods[s].pop_back();
//             }
//         } else if (i % 3 == 2) { 
//             // Case 2: Move between source (s) and auxiliary (a)
//             if (rods[s].empty() || (!rods[a].empty() && rods[s].back() > rods[a].back())) {
//                 // If source rod is empty or top disk on auxiliary is smaller, move disk from a to s
//                 rods[s].push_back(rods[a].back());
//                 cout << "Move disk " << rods[a].back() << " from rod " << a + 1 << " to rod " << s + 1 << endl;
//                 rods[a].pop_back();
//             } else {
//                 // Otherwise, move the top disk from source to auxiliary
//                 rods[a].push_back(rods[s].back());
//                 cout << "Move disk " << rods[s].back() << " from rod " << s + 1 << " to rod " << a + 1 << endl;
//                 rods[s].pop_back();
//             }
//         } else if (i % 3 == 0) { 
//             // Case 3: Move between auxiliary (a) and destination (d)
//             if (rods[a].empty() || (!rods[d].empty() && rods[a].back() > rods[d].back())) {
//                 // If auxiliary rod is empty or top disk on destination is smaller, move disk from d to a
//                 rods[a].push_back(rods[d].back());
//                 cout << "Move disk " << rods[d].back() << " from rod " << d + 1 << " to rod " << a + 1 << endl;
//                 rods[d].pop_back();
//             } else {
//                 // Otherwise, move the top disk from auxiliary to destination
//                 rods[d].push_back(rods[a].back());
//                 cout << "Move disk " << rods[a].back() << " from rod " << a + 1 << " to rod " << d + 1 << endl;
//                 rods[a].pop_back();
//             }
//         }
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the number of disks: ";
//     cin >> n;

//     int sourceRod = 1;
//     int destinationRod = 3;
//     int auxiliaryRod = 2;

//     towerOfHanoiIterative(n, sourceRod, destinationRod, auxiliaryRod);

//     return 0;
// }
