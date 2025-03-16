// Every node in a Binary Tree, stores three values. First it stores the data of the node, and it has left pointer (address of left child) and right pointer (address of right child).
// If a node doesn't have left or right child, then store NULL in there place.

// We will make individual nodes using Queue data structure. Queue will store the address of nodes. Then we can use these to access left and right pointers of nodes and store addresses of their child in them.
// If we get -1 as input, it means that we don't have to make a child (left or right depending on the order) for this node. By default, it is NULL in our constructor, so we need not specify NULL in this case ourselves.

#include <bits/stdc++.h>
using namespace std;

// Define the Node class, which will represent a single node in a binary tree
class Node {
    public:

    int data;         // This stores the value/data for the current node
    Node* left;       // Pointer to the left child (or NULL if no left child)
    Node* right;      // Pointer to the right child (or NULL if no right child)

    // Constructor to initialize a node with the given data.
    // By default, the left and right pointers are set to NULL because initially, the node has no children.
    Node(int data) {
        this->data = data;     // Assign data to the node
        this->left = NULL;     // No left child yet, so set to NULL
        this->right = NULL;    // No right child yet, so set to NULL
    }
};

int main() {
    queue <Node*> q;   // We are using a queue to store nodes whose children are yet to be assigned
    int first, second, rootElement;  // Variables to hold input values

    // Prompt user to enter the value for the root node
    cout << "Enter the root element :- ";
    cin >> rootElement;

    // Create the root node with the user input value and push it onto the queue
    Node* root = new Node(rootElement);  // Root is created
    q.push(root);                        // Add root node to the queue

    // Start a loop that will continue until all nodes are processed (queue is empty)
    while (!q.empty()) {
        Node* temp = q.front();   // Get the front node from the queue (the current node we are working on)
        q.pop();                  // Remove it from the queue (as we will now process it)

        // Prompt user to input the left child for the current node (or -1 if no left child)
        cout << "Enter -1 if there is no left child for " << temp->data << endl;
        cout << "Enter the left child of " << temp->data << " :- " ;
        cin >> first;

        // If the input for the left child is not -1, create the left child node
        if (first != -1) {
            temp->left = new Node(first);   // Create a new node and assign it to the left pointer
            q.push(temp->left);             // Add this new left child node to the queue for future processing
        }

        // Prompt user to input the right child for the current node (or -1 if no right child)
        cout << "Enter -1 if there is no right child for " << temp->data << endl;
        cout << "Enter the right child of " << temp->data << " :- " ;
        cin >> second;

        // If the input for the right child is not -1, create the right child node
        if (second != -1) {
            temp->right = new Node(second);  // Create a new node and assign it to the right pointer
            q.push(temp->right);             // Add this new right child node to the queue for future processing
        }
    }

    // After this loop completes, the binary tree will have been built based on the user inputs.

    return 0;  
}
