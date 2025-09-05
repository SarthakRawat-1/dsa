// Problem Statement :- https://leetcode.com/problems/copy-list-with-random-pointer/description/


#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// First method to solve is to simply ignore random pointers. Just traverse the LL normally and create clones of nodes and link them accordingly.
// This will clone the LL with their nect ptrs. Now for even cloning the random ptrs, we will take two ptrs again, both starting from heads, one from original LL and one from our intermediate clone.
// Then in original LL, check if it has a random ptr, if yes find how many steps/nodes it is away from that. Using this u can also assign random ptr in the intermediate clone LL. After this, move both traversing ptrs by one.
// Btw as random ptrs can even point back, so while finding how many nodes it is away start from beginning of LL.
// Instead of counting first and then moving, you can find and compare addr and move the addr in both LL at the same time to arrive at destiantion node. Ofc address comaprison will only happenw ith original LL node but ptrs of both will move.
class Solution {
public:
    // Helper function to find the corresponding node in the clone list
    // curr1 traverses original list, curr2 traverses cloned list.
    // We stop when curr1 == x (i.e., when we locate the random pointer target).
    // At that point, curr2 will be the matching clone node.
    Node* find(Node* curr1, Node* curr2, Node* x) {
        if (!x) {  // If random pointer is NULL, return NULL
            return NULL;
        }

        // Traverse both lists simultaneously until we reach the random target
        while(curr1 != x) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        return curr2;  // The corresponding node in the cloned list
    }

    Node* copyRandomList(Node* head) {
        if (!head) return NULL;  // Edge case: empty list

        // Step 1: Create a copy list with only "next" pointers
        Node* headCopy = new Node(0);  // dummy node for simplicity
        Node* tailCopy = headCopy;     // pointer to build the clone list
        Node* temp = head;

        while(temp) {
            tailCopy->next = new Node(temp->val);  // copy the current node
            tailCopy = tailCopy->next;
            temp = temp->next;
        }

        // Remove dummy node, update headCopy to actual head
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;  // free dummy

        // Step 2: Assign random pointers
        tailCopy = headCopy;
        temp = head;

        while(temp) {
            // Find the corresponding clone node for temp->random
            tailCopy->random = find(head, headCopy, temp->random);

            // Move forward in both lists
            tailCopy = tailCopy->next;
            temp = temp->next;        
        }

        return headCopy;
    }
};

// Right now due to find func, we get O(N^2), if we can find in O(1) time it'll reduce Time Complexity.
// So, use a map which store addresses. It will map the the corresponding nodes addr between original and cloned LL.  
// Optimized solution using a hashmap
// ----------------------------------
// Right now, in the previous solution, the "find" function caused O(N) work
// for each node when assigning random pointers → overall O(N^2).
//
// Optimization idea:
// If we can directly find the cloned node corresponding to any original node
// in O(1), we can fix random pointers in a single traversal.
//
// Solution:
// Use a hash map that stores address mapping:
//     original node address -> cloned node address
//
// This lets us set random pointers in O(1) instead of O(N).

Node* copyRandomList(Node* head) {
    if (!head) return NULL;  // Edge case: empty list

    // Step 1: Create a copy list with only "next" pointers
    Node* headCopy = new Node(0);  // dummy node for simplicity
    Node* tailCopy = headCopy;     // pointer to build the clone list
    Node* temp = head;

    while(temp) {
        tailCopy->next = new Node(temp->val);  // create a new node with same value
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    // Remove dummy node, update headCopy to actual head
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;  // free dummy

    // Step 2: Build a map from original node addresses to cloned node addresses
    tailCopy = headCopy;
    temp = head;

    unordered_map<Node*, Node*> mp;  // mapping: original -> cloned

    while(temp) {
        mp[temp] = tailCopy;  // store mapping of corresponding nodes
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    // Step 3: Assign random pointers using the map
    temp = head;
    tailCopy = headCopy;

    while(temp) {
        // temp->random gives an original node's random pointer
        // mp[temp->random] gives the cloned node corresponding to it
        tailCopy->random = mp[temp->random];  

        // move both pointers ahead
        temp = temp->next;
        tailCopy = tailCopy->next;
    }

    return headCopy;  // return deep-copied list
}

// Now we can also reduce space complexity to O(1). This is interweaving method.
// Instead of using an extra unordered_map, we temporarily merge (interweave) the original and cloned nodes in one linked list, so we can directly access the clone of any node in O(1).
Node* copyRandomList(Node* head) {
    if (!head) return NULL;  // Edge case: empty list

    // ----------------------------------------------------
    // Step 1: Create a clone list (just values, only "next")
    // ----------------------------------------------------
    Node* headCopy = new Node(0);  // dummy node for simplicity
    Node* tailCopy = headCopy;     // pointer to build the clone list
    Node* temp = head;

    while(temp) {
        tailCopy->next = new Node(temp->val);  // create a new node with same value
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    // Remove dummy node, update headCopy to actual head
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;  // free dummy

    // ----------------------------------------------------
    // Step 2: Interweave original list with cloned list
    // ----------------------------------------------------
    // Idea: For each original node, link it to its clone.
    // Then link clone to original's next.
    //
    // Example: A -> B -> C
    // After this step: A -> A' -> B -> B' -> C -> C'
    //
    Node* curr1 = head;       // original list pointer
    Node* curr2 = headCopy;   // cloned list pointer
    Node* front1, *front2;

    while(curr1) {
        front1 = curr1->next;   // save original next
        front2 = curr2->next;   // save clone next

        curr1->next = curr2;    // link original to its clone
        curr2->next = front1;   // link clone to original's next

        // move both pointers ahead
        curr1 = front1;
        curr2 = front2;
    }

    // ----------------------------------------------------
    // Step 3: Assign random pointers for the cloned nodes
    // ----------------------------------------------------
    curr1 = head;
    while(curr1) {
        curr2 = curr1->next;  // clone node (always next of original)

        if (curr1->random) {
            // Original's random points to some node X.
            // Its clone will be at X->next (since every original is followed by its clone).
            curr2->random = curr1->random->next;
        }

        curr1 = curr2->next;  // move to next original node
    }

    // ----------------------------------------------------
    // Step 4: Separate original and cloned lists
    // ----------------------------------------------------
    curr1 = head;
    while(curr1->next) {
        front1 = curr1->next;        // this is clone node
        curr1->next = front1->next;  // restore original link
        curr1 = front1;              // move ahead (clone becomes next curr1 temporarily)
    }

    // ----------------------------------------------------
    // Return head of cloned list
    // ----------------------------------------------------
    return headCopy;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

}