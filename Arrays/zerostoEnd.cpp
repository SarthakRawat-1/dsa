#include <bits/stdc++.h>

using namespace std;

vector<int> moveZeros(vector<int>& a) {
    int n = a.size(), nonZeroIndex = 0;

    // Step 1: Move all non-zero elements forward, maintaining their order.
    // 'nonZeroIndex' keeps track of the position where the next non-zero element should be placed.
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[nonZeroIndex++] = a[i]; // Place the non-zero element at 'nonZeroIndex' and increment it.
        }
    }

    // Step 2: Fill the remaining positions (from 'nonZeroIndex' to 'n-1') with zeros.
    for (int i = nonZeroIndex; i < n; i++) {
        a[i] = 0;
    }

    return a; // Return the modified array.
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;

    vector<int> ans = moveZeros(arr);

    for (auto &it : ans) {
        cout << it << " ";
    }

    cout << '\n';
    
    return 0;
}

