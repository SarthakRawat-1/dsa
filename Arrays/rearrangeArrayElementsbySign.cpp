// Problem Statement :- https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// Brute Force :- Since the number of positive and negative elements are the same, we put positives into an array called “pos” and negatives into an array called “neg”. After segregating each of the positive and negative elements, we start putting them alternatively back into array A. Since the array must begin with a positive number and the start index is 0, so all the positive numbers would be placed at even indices (2*i) and negatives at the odd indices (2*i+1), where i is the index of the pos or neg array while traversing them simultaneously.

#include<bits/stdc++.h>
using namespace std;

vector<int> RearrangebySign(vector<int>A, int n){
    
  // Step 1: Vectors to store positive and negative numbers separately
  vector<int> pos; // To store all positive integers
  vector<int> neg; // To store all negative integers
  
  // Step 2: Segregate the input array into positive and negative numbers
  for(int i = 0 ; i < n ; i++){
      
      if(A[i] > 0) {
       pos.push_back(A[i]); // Add to pos vector if number is positive
      }  
      else {
       neg.push_back(A[i]); // Add to neg vector if number is negative
      }
  }

  // You can create a new vector to store the result if you want. But here we are going to make changes in the original vector.
  
  // Step 4: Fill the result array by placing positive numbers at even indices (0, 2, 4, ...)
  // and negative numbers at odd indices (1, 3, 5, ...).
  // Since the input guarantees an equal number of positives and negatives,
  // we can alternate between positive and negative numbers.
  for(int i = 0 ; i < n/2 ; i++){
      A[2 * i] = pos[i]; // Insert positive numbers at even indices in the result
      A[2 * i + 1] = neg[i]; // Insert negative numbers at odd indices in the result
  }
  
  return A;  // Do note that he original vector A is not modified because we have passed it by value not by reference.
}

int main() {
    
  int n = 4;
  vector<int> A {1,2,-4,-5};

  vector<int> ans = RearrangebySign(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

// Optimal Method :- We will try to solve the problem in a single pass and try to arrange the array elements in the correct order in that pass only.
// We know that the resultant array must start from a positive element so we initialize the positive index as 0 and negative index as 1 and start traversing the array such that whenever we see the first positive element, it occupies the space at 0 and then posIndex increases by 2 (alternate places).
// Similarly, when we encounter the first negative element, it occupies the position at index 1, and then each time we find a negative number, we put it on the negIndex and it increments by 2.
// When both the negIndex and posIndex exceed the size of the array, we see that the whole array is now rearranged alternatively according to the sign.

#include<bits/stdc++.h>
using namespace std;

// Function to rearrange elements in the array based on their sign
// Positive elements are placed at even indices, and negative elements are placed at odd indices
vector<int> RearrangebySign(vector<int>A){
    
    int n = A.size(); // Get the size of the array

    // Step 1: Define a new array 'ans' to store the rearranged elements
    // It has the same size as 'A', initialized to 0
    vector<int> ans(n, 0);
  
    // Step 2: Initialize indices for positive and negative elements
    // 'posIndex' starts from 0 because positive numbers will be placed at even indices
    // 'negIndex' starts from 1 because negative numbers will be placed at odd indices
    int posIndex = 0, negIndex = 1;
  
    // Step 3: Traverse the input array and place elements in the 'ans' array based on their sign
    for(int i = 0; i < n; i++){
      
        // If the current element is negative, place it at the 'negIndex' (odd index)
        if(A[i] < 0){
            ans[negIndex] = A[i];  // Place the negative element
            negIndex += 2;  // Increment by 2 to move to the next odd index
        }
      
        // If the current element is positive, place it at the 'posIndex' (even index)
        else{
            ans[posIndex] = A[i];  // Place the positive element
            posIndex += 2;  // Increment by 2 to move to the next even index
        }
    }
  
    // Step 4: Return the rearranged array
    return ans;
}
  
int main() {

    vector<int> A = {1, 2, -4, -5};

    vector<int> ans = RearrangebySign(A);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";  
    }
  
    return 0;
}


// Other Variety :- There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.
// Intution :- In this variety, the number of positive and negative numbers shall not necessarily be equal to each other in the given array. So, there can be two cases possible: either the positive elements exceed the negatives or the negatives exceed the positives. So, instead of using the optimal solution discussed for the variety-1 above, we’ll fall back to the brute force solution where we create separate arrays for storing positives and negatives and then put them back into the array alternatively. The remaining negative or positive elements are added to the array at last.

#include<bits/stdc++.h>
using namespace std;

// Function to rearrange elements in the array such that positive and negative elements alternate.
// If the number of positive and negative elements is not equal, the remaining elements are appended at the end.
vector<int> RearrangebySign(vector<int> A, int n){

    // Step 1: Define two vectors to store positive and negative elements separately.
    vector<int> pos; // Stores all positive elements
    vector<int> neg; // Stores all negative elements

    // Step 2: Traverse the array and segregate the elements based on their sign.
    for(int i = 0; i < n; i++){

        if(A[i] > 0) 
            pos.push_back(A[i]); // Push positive elements to the 'pos' vector.
        else 
            neg.push_back(A[i]); // Push negative elements to the 'neg' vector.
    }

    // Step 3: Check if the number of positive elements is less than the negative elements.
    if(pos.size() < neg.size()){
      
        // Step 4: Alternately place positive and negative elements in the array 'A'
        // Loop until the count of positive elements is exhausted.
        for(int i = 0; i < pos.size(); i++){
            A[2 * i] = pos[i]; // Place positive elements at even indices (0, 2, 4, ...)
            A[2 * i + 1] = neg[i]; // Place negative elements at odd indices (1, 3, 5, ...)
        }

        // Step 5: If there are more negative elements, place the remaining negative elements at the end of the array.
        int index = pos.size() * 2; // Start placing negatives after the last alternating pair.
        for(int i = pos.size(); i < neg.size(); i++){
            A[index] = neg[i]; // Place the remaining negative elements.
            index++; // Move to the next index in the array.
        }
    }
    // Step 6: Check if the number of negative elements is less than or equal to positive elements.
    else {
      
        // Step 7: Alternately place positive and negative elements in the array 'A'
        // Loop until the count of negative elements is exhausted.
        for(int i = 0; i < neg.size(); i++){
            A[2 * i] = pos[i]; // Place positive elements at even indices.
            A[2 * i + 1] = neg[i]; // Place negative elements at odd indices.
        }

        // Step 8: If there are more positive elements, place the remaining positive elements at the end of the array.
        int index = neg.size() * 2; // Start placing positives after the last alternating pair.
        for(int i = neg.size(); i < pos.size(); i++){
            A[index] = pos[i]; // Place the remaining positive elements.
            index++; // Move to the next index in the array.
        }
    }

    // Step 9: Return the modified array 'A' with the rearranged elements.
    return A;
}

int main() {
    
    int n = 6;
    vector<int> A {1, 2, -4, -5, 3, 4};

    vector<int> ans = RearrangebySign(A, n);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " "; 
    }

    return 0;
}
