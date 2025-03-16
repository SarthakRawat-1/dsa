// Problem Statement :- Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. Find the number(between 1 to N), that is not present in the given array.
// One approach to solve this is via Linear search. For each number between 1 to N, we will try to find it in the given array using linear search. And if we don’t find any of them, we will return the number.
// This algorithm works as follows :- We will run a loop(say i) from 1 to N. For each integer, i, we will try to find it in the given array using linear search. For that, we will run another loop to iterate over the array and consider a flag variable to indicate if the element exists in the array. Flag = 1 means the element is present and flag = 0 means the element is missing. Initially, the flag value will be set to 0. While iterating the array, if we find the element, we will set the flag to 1 and break out from the loop. Now, for any number i, if we cannot find it, the flag will remain 0 even after iterating the whole array and we will return the number.

// A better way to solve this is using Hashing. Using the hashing technique, we will store the frequency of each element of the given array. Now, the number( i.e. between 1 to N) for which the frequency will be 0, will be returned.

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& a, int N) {
    // Step 1: Create a hash array initialized to 0, 
    // size N + 1 to account for numbers from 1 to N
    int hash[N + 1] = {0};
    // The reason why we are taking N + 1 instead of N is because In this problem, we are given N - 1 numbers (i.e., one number is missing from the sequence), and we need to find the missing number from the range [1, N]. To easily map the numbers from 1 to N, we need an array that can hold N indices. However, array indices in C++ start from 0, so for an array that can represent numbers from 1 to N, the array needs to have a length of N + 1.
    // Suppose N = 5, meaning the numbers you expect are in the range [1, 5]. The missing number might be any number from this range.
    // You need the hash[] array to have space for indices from 1 to 5. hash[1] will store the count of the number 1. hash[5] will store the count of the number 5.

    // Step 2: Store the frequencies of each number in the array 'a'
    // Loop through the array and increase the count of the corresponding index in hash
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++; // For i = 0, a[i] will be 1 for our vector a, so hash[1] will be incremented so it also becomes 1 now from 0.
        // As in our vector a, 3 is not present so for no value of i, a[i] will be 3, so in hash array, hash[3] will still be zero.

    // Step 3: Check the frequencies for numbers 1 to N in the hash array
    // The number with a frequency of 0 is the missing number
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;  // Return the missing number
        }
    }

    // This return statement is redundant, and it will never be executed.
    // It's added to avoid compiler warnings in case of incomplete paths.
    return -1;
}

int main() {
    // Input size N and vector 'a' with numbers from 1 to N-1, but one number is missing
    int N = 5;
    vector<int> a = {1, 2, 4, 5};

    // Call the function to find the missing number
    int ans = missingNumber(a, N);

    cout << "The missing number is: " << ans << endl;

    return 0;
}


// An even better approach to solve this problem is using XOR operation. But i won't write it here. Check that out on A2Z sheet.

// Another better approach is the summation approach.
// We know that the summation of the first N numbers is (N*(N+1))/2. We can say this S1. Now, in the given array, every number between 1 to N except one number is present. So, if we add the numbers of the array (say S2), the difference between S1 and S2 will be the missing number. Because, while adding all the numbers of the array, we did not add that particular number that is missing.

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>&a, int N) {
    
    // Step 1: Calculate the summation of first N numbers using the formula:
    // sum = N * (N + 1) / 2
    // This formula gives the total sum of all numbers from 1 to N if none were missing.
    int sum = (N * (N + 1)) / 2;

    // Step 2: Calculate the summation of all elements present in the array.
    // This will give us the sum of all numbers except the missing one.
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i]; // Add each element of the array to s2.
    }

    // Step 3: The missing number is the difference between the total sum (sum)
    // and the sum of the array elements (s2).
    int missingNum = sum - s2;

    // Return the missing number.
    return missingNum;
}

int main()
{
    int N = 5;

    vector<int> a = {1, 2, 4, 5};

    int ans = missingNumber(a, N);

    cout << "The missing number is: " << ans << endl;

    return 0;
}
