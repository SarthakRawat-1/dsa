// Problem Statement :- https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

// A simple approach is to divide the array in half and use them to implement both stacks.
// This however is not an efficient method.

// Optimized Appraoch :- Take a top1 pointer at -1 (before beginning of array) and top2 pointer at n (after end of array). top1 will move to the right and top2 will move to the left, when we are pushing elements in stack.
// For pop operation, top1 will move to the left and top2 will move to the right. When top1 + 1 == top2, it means no more space is left in array, so we can't push elements in any of the stack.

#include <bits/stdc++.h>
using namespace std;

class twoStacks {
public:
    int *arr;    // Pointer to the array holding both stacks
    int top1;    // Pointer for the top of the first stack (starts at -1)
    int top2;    // Pointer for the top of the second stack (starts at size)
    int size;    // Total size of the array

    // Constructor to initialize the array and stack pointers
    twoStacks(int n) {
        arr = new int[n]; // Allocate memory for the array
        size = n;         // Set the size of the array
        top1 = -1;        // Initialize top1 to -1 (empty stack)
        top2 = n;         // Initialize top2 to size (empty stack)
    }

    // Method to push an element to the first stack
    void push1(int x) {
        // Check if there is space available between top1 and top2
        if (top1 + 1 == top2) {
            return; // Stack overflow, no space to push
        }

        top1++;          // Move top1 to the next position
        arr[top1] = x;   // Insert the element
    }

    // Method to push an element to the second stack
    void push2(int x) {
        // Check if there is space available between top2 and top1
        if (top2 - 1 == top1) {
            return; // Stack overflow, no space to push
        }

        top2--;          // Move top2 to the previous position
        arr[top2] = x;   // Insert the element
    }

    // Method to pop an element from the first stack
    int pop1() {
        // Check if the first stack is empty
        if (top1 == -1) {
            return -1; // Stack underflow
        }

        int element = arr[top1]; // Retrieve the top element
        top1--;                  // Move top1 back
        return element;
    }

    // Method to pop an element from the second stack
    int pop2() {
        // Check if the second stack is empty
        if (top2 == size) {
            return -1; // Stack underflow
        }

        int element = arr[top2]; // Retrieve the top element
        top2++;                  // Move top2 forward
        return element;
    }
};

int main() {
    int n = 100; // Size of the array for both stacks

    twoStacks ts(n); // Create an instance of twoStacks

    // Example usage
    ts.push1(5);    // Push 5 to stack 1
    ts.push2(10);   // Push 10 to stack 2

    cout << ts.pop1() << endl; // Pop from stack 1 (output: 5)
    cout << ts.pop2() << endl; // Pop from stack 2 (output: 10)

    return 0;
}
