// Problem Statement :- https://www.geeksforgeeks.org/problems/assign-mice-holes3053/0

// Let's say we have M = {4, -4, 2} and H = {4, 0, 5}
// For simplicity, try to imagine these positions on x axis. 
// Let's say we want to send -4 from M to 4 on H, this will take 8 min. We want to send 4 from M to 0 on H, which will take 4 min. We want to send 2 from M to 5 on H, which will take 3 min.
// So we know, that after 8 min, all mice are in their holes, hence it took 8 min in this case. We want to minimize this time.
// For minimum time, we will simply sort M and H, and then assign M[0] to H[0] and M[1] to H[1] and M[2] to H[2] in this order.
// This greedy pairing minimizes the distance for each mouse, ensuring that the longest travel distance is as short as possible.
// Sorting preserves relative order, so pairing elements in sorted order minimizes individual distances.
// If we were to mismatch mice and holes (e.g., smallest mouse with largest hole), it could lead to unnecessarily long distances for some mice, increasing the maximum time.

#include <bits/stdc++.h>
using namespace std;

int assignMiceHoles(int N, int M[], int H[]) {
    sort(M, M + N); // Sort M in ascending order
    sort(H, H + N); // Sort H in ascending order

    int ans = INT_MIN; 

    for (int i = 0; i < N; i++) {
        ans = max(ans, abs(M[i] - H[i])); // Update the maximum distance
    }

    return ans;
}

int main() {
    int N = 3;
    int M[] = {4, -4, 2};
    int H[] = {4, 0, 5};
    int ans = assignMiceHoles(N, M, H);
    cout << ans << endl;
    return 0;
}