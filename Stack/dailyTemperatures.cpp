// Problem Statement :- https://leetcode.com/problems/daily-temperatures/description/

// This is pretty much like onlineStockSpan.cpp

// Problem Statement :- https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size(); // Get the size of the temperatures array
    stack<int> st; // Stack to store indices of temperatures array

    // Result vector to store the number of days until a warmer temperature
    vector<int> result(n); 

    // Iterate over the temperatures array from right to left (reverse order)
    for (int i = n - 1; i >= 0; i--) {

        // Pop elements from the stack as long as the current temperature is 
        // greater than or equal to the temperature at the top of the stack.
        // We do this because we want the next warmer temperature, 
        // and if the current temperature is greater or equal, 
        // the stack top can't be the next warmer day.
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
            st.pop(); // Pop the top of the stack because it's not useful anymore
        }

        // If the stack is empty, that means there is no warmer temperature in the future,
        // so set result[i] to 0 (indicating no warmer day ahead).
        if (st.empty()) {
            result[i] = 0;
        } 
        // Otherwise, the top of the stack is the index of the next warmer day.
        // Calculate the difference in days (st.top() - i) and store it in result[i].
        else {
            result[i] = st.top() - i;
        }

        // Push the current index onto the stack, as it might be the next warmer day for a previous element
        st.push(i);
    }

    return result; // Return the result array
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73}; // Example input temperatures
    vector<int> result = dailyTemperatures(temperatures); // Call the function

    cout << "Days until a warmer temperature: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}
