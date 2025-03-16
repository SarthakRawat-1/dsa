// Problem Statement :- https://leetcode.com/problems/linked-list-random-node/description/

// Simple Approach :- Put LL into an array. Then simply pick a random element from the array using rand() % size of array.
// Reservoir Sampling :- It is a randomized algorithm used to select a sample of k items from a potentially large or unknown-size stream of data, where each item has an equal probability of being selected.
// The algorithm maintains a "reservoir" of kk elements. As new elements in the stream are processed, the algorithm decides whether to include each element in the reservoir, ensuring that the probability of any element being selected remains uniform.
// Steps of Reservoir Sampling :-
// Initialization:
// Fill the reservoir with the first k elements of the stream.
// Processing the Stream:
// For each subsequent element (starting from the (k+1)th element): Generate a random number r between 0 and the current index i (inclusive). If r<k, replace the rth element in the reservoir with the current element.
// Output: After processing the entire stream, the reservoir contains a uniform random sample of k elements from the stream.

// Please check Reservoir Sampling explanation for this question yourself.

#include <bits/stdc++.h>
using namespace std;

// Definition for a singly-linked list node.
class ListNode {
public:
    int val;             // Value of the node (data)
    ListNode* next;      // Pointer to the next node in the list

    // Constructor to initialize a new node
    ListNode(int value) {
        val = value;
        next = NULL;
    }
};

// Simple Approach
class Solution {
    public :
    vector<int> arr;

    Solution(ListNode* head) {
        ListNode* temp = head;

        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }    
    }
    
    int getRandom() {
        int n = arr.size();

        int random_index = rand() % n;
        
        return arr[random_index];
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Create a cycle for testing (link the last node back to the second node)
    head->next->next->next->next = head->next; // -4 -> 2

    // Print the original linked list
    cout << "Original Linked List: ";
    printList(head);    

    // Create a Solution object
    Solution solution(head);

    // Get a random node from the linked list
    int randomNode = solution.getRandom();

    // Print the random node
    cout << "Random Node: " << randomNode << endl;

    return 0;
}
