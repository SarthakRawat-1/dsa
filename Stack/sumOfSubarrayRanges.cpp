// Problem Statement :- https://leetcode.com/problems/sum-of-subarray-ranges/description/

// This is just an extension of Sum of Subarray Minimum.

#include <bits/stdc++.h>
using namespace std;

// ----- Nearest Smaller to Left -----
vector<int> getNSL(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return result;
}

// ----- Nearest Smaller to Right -----
vector<int> getNSR(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        result[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return result;
}

// ----- Nearest Greater to Left -----
vector<int> getNGL(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return result;
}

// ----- Nearest Greater to Right -----
vector<int> getNGR(vector<int>& arr, int n) {
    vector<int> result(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        result[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return result;
}

// Sum of subarray minimums
long long sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> NSL = getNSL(arr, n);
    vector<int> NSR = getNSR(arr, n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        long long d1 = i - NSL[i];
        long long d2 = NSR[i] - i;
        sum = (sum + 1LL * arr[i] * d1 * d2);
    }
    return sum;
}

// Sum of subarray maximums
long long sumSubarrayMaxs(vector<int>& arr) {
    int n = arr.size();
    vector<int> NGL = getNGL(arr, n);
    vector<int> NGR = getNGR(arr, n);
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        long long d1 = i - NGL[i];
        long long d2 = NGR[i] - i;
        sum = (sum + 1LL * arr[i] * d1 * d2);
    }
    return sum;
}

// Final: Sum of Subarray Ranges
long long subArrayRanges(vector<int>& arr) {
    long long sumMax = sumSubarrayMaxs(arr);
    long long sumMin = sumSubarrayMins(arr);
    return (sumMax - sumMin); 
}


int main() {

}