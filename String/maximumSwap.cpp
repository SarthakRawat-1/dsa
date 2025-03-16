// Problem Statement :- https://leetcode.com/problems/maximum-swap/description/?envType=daily-question&envId=2024-10-17

// Consider :- 2736 As we only have to swap only once. We will try to do it such that biggest digit goes to most significant position. But if it is already at most significant position, then we will try to bring second biggest digit to second most significant position. If that is also there, then try for third biggest number and so on.
// Consider :- 9379 Here, the 9 at thousandth place, there's no digit greater than it on the right side, so it is at it's correct place. Now coming to 3, the biggest digit to the right of it is, 9. So swap both. 9973 is the answer.

// First, we will make an array where each index will store the index of max element to the right of it in the number. Eg :- For 2376, it'll be {2 ,2 ,2 ,3}
// Then using this array, we know what number to swaps.
// For eg :- 9937 has the array :- {0, 1, 3, 3} Now, starting from 9937, we can see for first element, our array stores 0, meaning it itself is the biggest number. So no, swap. Same goes for second 9 which has 1 stored in index 1 at array. But for 3 in array, it is stored 3. Hence, swap this with 7.

#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
    // Convert the input number to a string to easily manipulate individual digits
    string s = to_string(num);
    int n = s.length(); // Get the length of the number string

    // Create a vector to store the index of the maximum element to the right of each index
    vector<int> maxRight(n);

    // Initialize the last element of maxRight as the last index of the string (rightmost element)
    maxRight[n - 1] = n - 1;

    // Loop backwards through the string to populate maxRight vector
    for (int i = n - 2; i >= 0; i--) {
        int rightMaxIndex = maxRight[i + 1]; // Get the index of the largest element to the right of current index
        int rightMaxElement = s[rightMaxIndex]; // Get the largest element itself
        
        // If the current element is greater than or equal to the largest element on its right,
        // set the maxRight[i] to the current index (i). Otherwise, carry forward the rightMaxIndex.
        maxRight[i] = (s[i] > rightMaxElement) ? i : rightMaxIndex;
    }

    // Loop forward through the string to find the first place where swapping will result in a larger number
    for (int i = 0; i < n; i++) {
        int rightMaxIndex = maxRight[i]; // Get the index of the maximum element to the right
        int rightMaxElement = s[rightMaxIndex]; // Get the value of the maximum element
        
        // If the current digit is smaller than the maximum digit on its right, swap them
        if (s[i] < rightMaxElement) {
            swap(s[i], s[rightMaxIndex]); // Swap the digits
            return stoi(s); // Convert the modified string back to an integer and return it
        }
    }

    // If no swap was performed, return the original number
    return num;
}

int main() {
    int num = 2736;
    cout << maximumSwap(num) << endl;
}


// A Better approach is doing this without using an array

// Instead of an array with same length as that of the number, we will make an array os size 10, because we know that there are total 10 digits.
// For every element, we want to find the index of the maximum element to the right of it. So, we will first find the rightmost appearance of every digit. 
// Consider 9937, starting from 9, it is at index 0, so in vector, at index 9, store 0. Then next digit is also 9, at index 1. So update index 9 in vector with 1. Then comes 3 at index 2, so store 2 at index 3 in vector. Then comes 7 at index 3, so store 3 at index 7. Make the rest as -1 in vector.
// Now, again iterate over the number, we got 9, just check if there's any element greater than 9 using the help of array. There is none, so keep it at that. Same for the next 9. Then comes 3, we know from array that both 9 and 7 are greater than 3. But index 3 stores 2 and index 9 stores 1 and index 7 stores 3. As 1 is smaller than 2, this means 9 comes to left, so we can;t swap3 with them. We have to swap 3 with 7.

#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num) {
    // Convert the integer num to a string so that we can manipulate individual digits
    string s = to_string(num);
    int n = s.length(); // Get the length of the number string

    // Create a vector to store the rightmost position of each digit (0-9) in the number string
    vector<int> maxRight(10, -1); // Initialize all positions with -1 (no digits found yet)

    // First loop to fill the maxRight vector
    for (int i = 0; i < n; i++) {
        int idx = s[i] - '0'; // Get the numeric value of the current character (0-9)
        maxRight[idx] = i; // Store the index of this digit, representing the last occurrence of this digit
    }

    // Second loop to find the first place where a beneficial swap can occur
    for (int i = 0; i < n; i++) {
        char currChar = s[i]; // Get the current character in the string
        char currDigit = currChar - '0'; // Convert the character to its numeric digit value

        // Check if any digit greater than the current digit appears later in the number
        for (int j = 9; j > currDigit; j--) { // Traverse digits from 9 down to current digit + 1
            // If a larger digit exists to the right of the current digit, perform a swap
            if (maxRight[j] > i) { // Ensure the rightmost occurrence of j is after the current index i
                swap(s[i], s[maxRight[j]]); // Swap the current digit with the larger digit found
                return stoi(s); // Convert the modified string back to an integer and return it
            }
        }
    }

    // If no beneficial swap was found, return the original number
    return num;
}

int main() {
    int num = 2736;
    cout << maximumSwap(num) << endl;
}