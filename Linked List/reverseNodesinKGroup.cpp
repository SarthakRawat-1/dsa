// Problem Statement :- https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Problem Statement :- https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

// Method 1 :- Let's say we want to reverse a particular k number of nodes. For this case, we can just tell each one of them to point to the node prev to them and break the next link for each one of them.
// Eg :- Say you have 2->3->4->6->8->7->5->9->11->17 and for now we want to reverse 8->7->5->9 (so LL looks like 2->3->4->6->9->5->7->8->11->17), so first we do 2->3->4->6<->8<-7<-5<-9 11->17 (this we can do using three pointers, prev, curr and front).
// Now obv we now want 6 to point to 9 (instead of 8), we will do it using pointers, first pointer on 6 and third pointer on 9. We also want 8 to point to 11 now (instead of 6), so second pointer on 8 and fourth pointer on 11.
// But this is not exactly our problem. We have to start from head and in this case, first will point to NULL (as it should come just before the first node in k group which happens to be head for this case).
// To solve this case, we will create a dummy node just before the first node. After reversing this group, the second pointer now points to the node just before the first node of next group. We will now do first == second and start our reversing process again.
// If the last group has less than k nodes, we need to reverse only those nodes. For this, we can simply check if curr is NULL or not.
// All this logic will run till first->next exists because first pointer tells us that nodes coming after it should be reversed. 

// Method 2 :- Store the Linked List data in a vector in groups of k and then reverse. Keep doing this till you have stored data of entire Linked List in the vector. Afterwards, just change the data in existing LL using this vector.

#include <iostream>
#include <vector>
using namespace std;

class NODE {
    public:
    int data; 
    NODE *next; 

    NODE(int value) {
        data = value;
        next = NULL;
    }
};

// Function to create Linked List using Recursion
NODE* CreateLinkedList(vector<int> v, int index, int size, NODE* prev ) {
    // Base Case. This will happen when index becomes equal to size meaning no more elements are left in the vector. Thus prev will be returned.
    // So now by returning prev in this, we are returning the address of the last node. We need this because this is where the HEAD pointer of our linked list will point to.
    if (index==size) {
        return prev;
    }
    // Please note that this is the actual value that the CreateLinkedList function will return when called. The other return statement is simply calling the same function again so this prev is being returned constantly from all the recursive calls of the function.

    // First, we have to create a node. It will have it's address. This address will be given to the next node being created. I have used prev keyword only for convienience becuase as we are adding a new node from beginning, it feels like a previous node.
    // Obv for the first node created, it's next pointer will be NULL. Hence, when we are calling the function in int main(), initial value of prev is NULL.

    NODE *temp;
    temp = new NODE(v[index]);
    temp->next = prev; 
    
    // After this, it will create a new node but now prev value will be updated with the address of the node created before. This value will then be assigned to next pointer of the new node
    return CreateLinkedList(v, index+1, size, temp);;
}

// Function to print the Linked List
void printList(NODE* head) {
    NODE* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

NODE* reverseKGroup(NODE* head, int k) {
    // Create a dummy node that acts as the starting point of the modified list.
    NODE* first = new NODE(0);
    first->next = head; // Link dummy node to the original head.
    head = first; // Update head to point to the dummy node.
    
    int x; // Variable to count nodes within a group.
    NODE* second; // Pointer to the start of the group.
    NODE* prev; // Pointer to the node preceding the current node.
    NODE* curr; // Pointer to the current node being processed.
    NODE* front; // Pointer to the node after the current node.

    // The loop continues as long as there are nodes left to process.
    while (first->next) {
        x = k; // Reset the counter to k for each group.
        second = first->next; // Point to the first node of the current group.
        prev = first; // Initialize prev to point to the node before the group.
        curr = first->next; // Start processing from the first node of the group.

        // Reverse the current group of k nodes.
        while (x && curr) { // Continue until k nodes are reversed or the list ends.
            front = curr->next; // Save the next node in the original sequence.
            curr->next = prev; // Reverse the pointer of the current node.
            prev = curr; // Move prev to the current node.
            curr = front; // Move curr to the next node in the original sequence.
            x--; // Decrement the counter for the group.
        }

        // After reversing the group, connect it to the rest of the list.
        first->next = prev; // Connect the node before the group to the new head of the group.
        second->next = curr; // Connect the end of the reversed group to the next group's first node.

        // Move the first pointer to the end of the current group.
        first = second;
    }

    // Remove the dummy node.
    first = head; // Save the address of the dummy node.
    head = head->next; // Update head to point to the real start of the list.
    delete first; // Free memory allocated for the dummy node.

    return head; // Return the updated head of the list.
}

int main() {
    NODE *HEAD;

    vector <int> v = {0, 2, 1, 2, 0, 2, 1, 1, 0, 0, 2};

    HEAD = NULL;
    HEAD = CreateLinkedList(v, 0, v.size(), HEAD);

    cout << "Original List: ";
    printList(HEAD);

    HEAD = reverseKGroup(HEAD, 3);

    cout << "List reversed in K groups: ";
    printList(HEAD);

    return 0;
}

// Using the function you can solve Reverse Nodes in K group problem.
// You will need to use a function to check if there are atleast k number of nodes 
// Here is the function to check that :-
// auto hasKNodes = [](ListNode* node, int k) {
//     while (node && k) {
//         node = node->next;
//         k--;
//     }
//     return k == 0;
// }; 
// With this, you can modify the while loop condition :- while (first->next && hasKNodes(first->next, k)) 