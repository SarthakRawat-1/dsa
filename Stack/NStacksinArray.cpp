// Problem Statement :- https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271

// This problem is an extension of twoStacksinArray.cpp

// Forget initially taht you are given an array. Consider that intially you are given P spaces and you have to implement N stacks with them (these spaces can be that of array or linked list etc).
// Let's say P = 9, and N = 3. In this case, we can take an array of size 3. 0 index will denote first stack, 1 will denote second stack, and 2 will denote third stack. Now if it asks, to push element 10 to first stack, then we will create a Linked list, store it's head at that index 0 of size N array, and the head index will point a node containing value 10.
// If it further asks us to push 20 to stack 1, we will insert at beginning, so head remains at index 0, and head now points to 20, 20->next stores 10. This is so we can ensure that top of stack is popped first.
// This same logic will follow for other stacks. 
// We will keep track of total elements (across all stacks), to know when the array is full.

// But the problem is that in our question, we have to store data in Array.
// So we will have to do mapping.
// For this, instead of elements, we will store their index in Linked list after pushing them in array. 
// For reducing time complexity, we will use a stack to store empty indexes of array. This will tell us where in array, we can push the next element. This is especially beneficial, when we combine the pop operations of a stack, which can leave empty spaces in the middle of an array.

#include <bits/stdc++.h>
using namespace std;

// Node class to represent elements in each stack's linked list.
// Each node stores an index in the main array and a pointer to the next node.
class Node {
public: 
    int index;       // Index in the main array where the element is stored
    Node *next;      // Pointer to the next node in the linked list (stack)

    Node(int x) {
        index = x;
        next = NULL;
    }
};

class NStack {
private:
    stack<int> freeIndices;  // Stack to keep track of available indices in the array
    int *arr;                // Main array to store the elements of all stacks
    Node **top;              // Array of pointers to the top node of each stack

public:
    // Constructor to initialize N stacks in an array of size S.
    NStack(int N, int S) {
        arr = new int[S];    // Allocate memory for the main array
        top = new Node*[N];  // Allocate memory for top pointers of N stacks

        // Initialize all top pointers to NULL (empty stacks)
        for (int i = 0; i < N; i++) {
            top[i] = NULL;
        }

        // Initially, all indices in the array are free. Push them into the freeIndices stack.
        for (int i = 0; i < S; i++) {
            freeIndices.push(i);
        }
    }

    // Pushes 'X' into the Mth stack. Returns true if successful, false if array is full.
    bool push(int x, int m) {
        if (freeIndices.empty()) {
            return false;    // No free space available
        }

        // Get the next free index from the stack
        int freeIndex = freeIndices.top();
        freeIndices.pop();

        // Store the element in the main array at the free index
        arr[freeIndex] = x;

        // Create a new node for the stack's linked list and update the top pointer
        Node *newNode = new Node(freeIndex);
        newNode->next = top[m - 1];  // m is 1-based, adjust to 0-based index
        top[m - 1] = newNode;

        return true;
    }

    // Pops the top element from the Mth stack. Returns -1 if the stack is empty.
    int pop(int m) {
        if (top[m - 1] == NULL) {
            return -1;   // Stack is empty
        }

        // Get the index of the top element from the stack's linked list
        Node *temp = top[m - 1];
        int elementIndex = temp->index;

        // Retrieve the element from the main array
        int element = arr[elementIndex];

        // Update the top pointer to the next node in the linked list
        top[m - 1] = temp->next;

        // Free the node and return the index to the freeIndices stack
        delete temp;
        freeIndices.push(elementIndex);

        return element;
    }
};

int main() {
    // Create 3 stacks in an array of size 6
    NStack stackManager(3, 6);

    // Push elements to different stacks
    cout << "Pushing to stack 1: " << stackManager.push(10, 1) << endl;  // true
    cout << "Pushing to stack 2: " << stackManager.push(20, 2) << endl;  // true
    cout << "Pushing to stack 3: " << stackManager.push(30, 3) << endl;  // true
    
    // Push more elements
    cout << "Pushing to stack 1: " << stackManager.push(40, 1) << endl;  // true
    cout << "Pushing to stack 2: " << stackManager.push(50, 2) << endl;  // true
    cout << "Pushing to stack 3: " << stackManager.push(60, 3) << endl;  // true
    
    // Try to push when array is full (should fail)
    cout << "Pushing to stack 1 (full): " << stackManager.push(70, 1) << endl;  // false

    // Pop elements from stacks (LIFO order)
    cout << "\nPopping from stacks:\n";
    cout << "Stack 1: " << stackManager.pop(1) << endl;  // 40 (last pushed element)
    cout << "Stack 2: " << stackManager.pop(2) << endl;  // 50
    cout << "Stack 3: " << stackManager.pop(3) << endl;  // 60

    // Push again after creating space
    cout << "\nPushing to stack 1: " << stackManager.push(70, 1) << endl;  // true

    // Pop remaining elements
    cout << "\nFinal pops:\n";
    cout << "Stack 1: " << stackManager.pop(1) << endl;  // 70 (new element)
    cout << "Stack 1: " << stackManager.pop(1) << endl;  // 10 (first element)
    cout << "Stack 2: " << stackManager.pop(2) << endl;  // 20
    cout << "Stack 3: " << stackManager.pop(3) << endl;  // 30

    // Try popping from empty stack
    cout << "Stack 1 (empty): " << stackManager.pop(1) << endl;  // -1

    return 0;
}