// Problem Statement :- https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/0

// Find Inorder Traversal of both BST (this will give sorted order). Then use two pointer approach.
// One pointer on 1st and another on 2nd traversal. When there is a mismatch, the lower data pointer should be moved by one.
// If there is a match, move both pointers by 1.

// Optimized Approach :- Inorder Traversal using Stack.
// Start from root. Put that in stack. Then keep going left as much as you can and put all of them in stack too.
// Then pop one element. It will be the first element in inorder traversal of tree. Now check if it has a right child. If not, then pop one more from Stack and it is the next element in Inorder traversal.
// Now let's say this had a right child. So now go to that child (put it in stack), and from that keep going left and pushing them into stack. Keep doing it till we get the whole Inorder Traaversal.
// Now maintain separate stacks for both BST. If top of stack of one is smaller than other, remove that and go to it's right child (and add that and all nodes by going to as left as possible to stack). If it's a leaf node, remove that and go to the next element in stack.
// When one of the stack becomes empty. Stop operation. The common elements obtained till there are the answer.

/******************************************************
 * C++ Program to Print Common Nodes in Two BSTs
 *
 * Problem Statement (GeeksforGeeks):
 * Given two BSTs, print the common nodes in these BSTs.
 *
 * Approach:
 * ---------
 * 1. Perform an inorder traversal on both BSTs. The inorder
 *    traversal of a BST produces a sorted sequence of nodes.
 * 2. Use two stacks to simulate the inorder traversal for both trees.
 *    - For each BST, push all the leftmost nodes into a stack.
 * 3. Use a two-pointer-like approach:
 *    - Compare the top elements of both stacks.
 *    - If the values are equal, record the value as a common node,
 *      move to the right subtree for both trees, and update the stacks.
 *    - If one value is smaller, move to the right subtree of that tree
 *      (after popping the smaller value) to get closer to a potential match.
 * 4. Repeat until either stack becomes empty.
 *
 * This method avoids storing the entire inorder traversal in an array,
 * thereby optimizing space usage.
 ******************************************************/

 #include <iostream>
 #include <vector>
 #include <stack>
 using namespace std;
 
 //--------------------------------------------------------------
 // Definition for a BST node.
 //--------------------------------------------------------------
 struct Node {
     int data;           // Data stored in the node
     Node* left;         // Pointer to the left child
     Node* right;        // Pointer to the right child
 
     // Constructor to initialize the node with a given value.
     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 };
 
 //--------------------------------------------------------------
 // Function to insert a value into the BST.
 // Maintains the BST property: left < root < right.
 //--------------------------------------------------------------
 Node* insert(Node* root, int key) {
     // If the tree is empty, create a new node.
     if (root == nullptr) {
         return new Node(key);
     }
     // If the key is less than the current node's data,
     // insert it in the left subtree.
     if (key < root->data) {
         root->left = insert(root->left, key);
     }
     // If the key is greater than the current node's data,
     // insert it in the right subtree.
     else if (key > root->data) {
         root->right = insert(root->right, key);
     }
     // Return the (unchanged) root pointer.
     return root;
 }
 
 //--------------------------------------------------------------
 // Function to find common nodes in two BSTs using two stacks.
 // Parameters:
 //   - root1: Pointer to the root of the first BST.
 //   - root2: Pointer to the root of the second BST.
 // Returns a vector containing the common node values.
 //--------------------------------------------------------------
 vector<int> findCommon(Node* root1, Node* root2) {
     vector<int> ans;            // Vector to store common nodes.
     stack<Node*> s1, s2;        // Stacks to perform inorder traversal on each BST.
 
     // Initialize the first stack by pushing all leftmost nodes of the first BST.
     while (root1) {
         s1.push(root1);
         root1 = root1->left;
     }
     
     // Initialize the second stack by pushing all leftmost nodes of the second BST.
     while (root2) {
         s2.push(root2);
         root2 = root2->left;
     }
 
     // Process nodes until one of the stacks becomes empty.
     while (!s1.empty() && !s2.empty()) {
         // Compare the top nodes of both stacks.
         if (s1.top()->data == s2.top()->data) {
             // Common node found; add it to the answer vector.
             ans.push_back(s1.top()->data);
 
             // Move to the right subtree of both nodes.
             root1 = s1.top()->right;
             root2 = s2.top()->right;
 
             // Pop the matched nodes from both stacks.
             s1.pop();
             s2.pop();
         }
         // If the top node in s1 has a larger value, then the common element might be
         // found in the right subtree of the node from s2. So, process the right subtree of s2.
         else if (s1.top()->data > s2.top()->data) {
             root2 = s2.top()->right;
             s2.pop();
         }
         // Otherwise, process the right subtree of the node from s1.
         else {
             root1 = s1.top()->right;
             s1.pop();
         }
 
         // For the updated root1, push all its left descendants onto s1.
         while (root1) {
             s1.push(root1);
             root1 = root1->left;
         }
 
         // Similarly, for the updated root2, push all its left descendants onto s2.
         while (root2) {
             s2.push(root2);
             root2 = root2->left;
         }
     }
 
     return ans;
 }
 
 //--------------------------------------------------------------
 // Main function to build the BSTs, find common nodes, and print them.
 //--------------------------------------------------------------
 int main() {
     // Build the first BST.
     // Example BST 1: {5, 1, 10, 0, 4, 7, 12}
     Node* root1 = nullptr;
     root1 = insert(root1, 5);
     insert(root1, 1);
     insert(root1, 10);
     insert(root1, 0);
     insert(root1, 4);
     insert(root1, 7);
     insert(root1, 12);
 
     // Build the second BST.
     // Example BST 2: {10, 7, 20, 4, 9}
     Node* root2 = nullptr;
     root2 = insert(root2, 10);
     insert(root2, 7);
     insert(root2, 20);
     insert(root2, 4);
     insert(root2, 9);
 
     // Find the common nodes between the two BSTs.
     vector<int> commonNodes = findCommon(root1, root2);
 
     // Print the common nodes.
     cout << "Common nodes in both BSTs are: ";
     for (int val : commonNodes) {
         cout << val << " ";
     }
     cout << endl;
 
     return 0;
 }
 